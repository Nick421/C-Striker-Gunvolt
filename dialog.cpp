#include "dialog.h"
#include "stickmanfactory.h"
#include "configreader.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent) :
  QDialog(parent),
  ui(new Ui::Dialog) {
  ui->setupUi(this);

  // make a config reader object and read the file
  configreader reader(":/config/config.txt");

  if (!loadConfig(reader)) {
    qWarning("load config fail, Default value will be used.");
  }

  // play the bgm
  m_music->play();

  // make a timer and start it
  m_timer = new QTimer(this);
  connect(m_timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
  m_timer->start(m_framerate);
}

Dialog::~Dialog() {
  delete m_character;
  delete m_background;
  delete m_music;
  delete m_timer;
  delete ui;
}

bool Dialog::loadConfig(const configreader& reader) {
  // variables to check for error in reading config files
  bool parseCheck = false;
  bool success = true;

  // parse the framerate
  int framerate = QString(reader.mapGet("FRAMERATE").c_str()).toInt(&parseCheck);

  if (!parseCheck || framerate <= 0) {
    framerate = 30;
    success = false;
  }

  m_framerate = 1000 / framerate;

  // parse the background
  QString background = reader.mapGet("BACKGROUND").c_str();
  QPixmap bgimage;

  if (!bgimage.load(background)) {
    bgimage.load(":/img/img/390.png");
    success = false;
  }

  // construct background object
  m_background = new class background(bgimage);

  // set screen size
  setFixedSize(bgimage.width(), bgimage.height());

  // get day duration in milliseconds
  int dayDuration = QString(reader.mapGet("DAYDURATION").c_str()).toInt(&parseCheck);

  if (!parseCheck || dayDuration < 0) {
    dayDuration = 60000;
    success = false;
  }

  // set day duration
  m_background->setDaytime(dayDuration);

  // parse the size of character
  QString charSize = reader.mapGet("CHARSIZE").c_str();

  if (charSize != "tiny" && charSize != "normal" && charSize != "large" && charSize != "giant") {
    charSize = "normal";
    success = false;
  }

  // parse sprite of the character
  QString spriteFilename = reader.mapGet("CHARSPRITE").c_str();
  QPixmap charSprite;

  if (!charSprite.load(spriteFilename)) {
    charSprite.load(":/img/img/gunvolt.png");
    success = false;
  }

  // produce the character
  m_character = stickmanfactory::produce(charSize.toStdString(), charSprite);

  // get character x offset
  int charX = QString(reader.mapGet("CHARXOFFSET").c_str()).toInt(&parseCheck);
  if (!parseCheck || !(charX >= 0 && charX < bgimage.width())) {
    charX = 0;
    success = false;
  }

  // set character x offset
  m_character->setXoffset(charX);

  // get character velocity
  int charVelocity = QString(reader.mapGet("CHARVELOCITY").c_str()).toInt(&parseCheck);

  if (!parseCheck || charVelocity < 0) {
    charVelocity = 3;
    success = false;
  }

  // set character velocity
  m_character->setVelocity(charVelocity);

  // get number of sprite in the sprite sheet for animation
  int charAnimationFrames = QString(reader.mapGet("CHARANIMATIONFRAMES").c_str()).toInt(&parseCheck);

  if (!parseCheck || charAnimationFrames < 0) {
    charVelocity = 0;
    success = false;
  }

  m_character->setNumberOfAnimationFrames(charAnimationFrames);

  // load bgm
  QString bgmFilename = reader.mapGet("BGM").c_str();

  // make playlist so bgm can loop
  auto* playlist = new QMediaPlaylist();
  m_music  = new QMediaPlayer(this);

  // add song from file path to playlist
  playlist->addMedia(QUrl(bgmFilename));

  if (m_music->error()) {
    playlist->addMedia(QUrl(":/music/music/epilouge.mp3"));
    success = false;
  }

  // get bgm volume
  int bgmvolume = QString(reader.mapGet("BGMVOLUME").c_str()).toInt(&parseCheck);
  if (!parseCheck || bgmvolume < 0 || bgmvolume > 100) {
    bgmvolume = 50;
    success = false;
  }

  m_music->setVolume(bgmvolume);

  // loop and set playlist
  playlist->setPlaybackMode(QMediaPlaylist::Loop);
  m_music->setPlaylist(playlist);

  return success;
}


void Dialog::paintEvent(QPaintEvent*  /*event*/) {
  // render the background and character
  QPainter painter(this);
  m_background->render(painter, -m_character->getVelocity());
  m_character->render(painter);
}

void Dialog::keyPressEvent(QKeyEvent* e) {
  // keyboard P for pause
  if (e->key() == Qt::Key_P) {
    pause();
  }
  // keyboard R to resume
  if (e->key() == Qt::Key_R) {
    resume();
  }
}

void Dialog::nextFrame() {
  update();
  // comment out next 2 lines to disable animation and day/night cycle
  m_character->nextFrame();
  m_background->update(300); // 300 is hardcoded value, can be change
}

void Dialog::pause() {
  disconnect(m_timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
  m_music->pause();
}

void Dialog::resume() {
  connect(m_timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
  m_music->play();
}
