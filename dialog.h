#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QPainter>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QKeyEvent>

#include "background.h"
#include "stickman.h"
#include "configreader.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
  Q_OBJECT

 public:
  explicit Dialog(QWidget* parent = nullptr);
  ~Dialog();

 public slots:
  void nextFrame();
  void pause();
  void resume();

 protected:
  void paintEvent(QPaintEvent* event);
  void keyPressEvent(QKeyEvent* e);

 private:
  /* initialise game from config file
   * returns false if config file is missing something
   * if false is returned, default value is used
  */
  bool loadConfig(const configreader& reader);
  Ui::Dialog* ui;
  QTimer* m_timer;
  background* m_background;
  stickman* m_character;
  int m_framerate;
  QMediaPlayer* m_music;
};

#endif // DIALOG_H
