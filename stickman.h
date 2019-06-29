#ifndef STICKMAN_H
#define STICKMAN_H

#include <QPainter>
#include <QPixmap>

enum Sizes {
  Tiny, Normal, Large, Giant
};

class stickman {

 public:
  // initialise a new stickman
  stickman(Sizes size, const QPixmap& image);
  virtual ~stickman();

  void render(QPainter& painter);
  void nextFrame();

  // return the corresponding scale to size
  int getSize();

  QPixmap getSprite();

  // bounding box of the stickman
  virtual int getWidth() = 0;
  virtual int getHeight() = 0;

  void setXoffset(int value);
  void setVelocity(int value);

  // X velocity of stickman
  int getVelocity();

  int getNumberOfAnimationFrames();
  void setNumberOfAnimationFrames(int numFrames);

  // get each sprite size in spritesheet
  int getAnimationBlock();

 private:
  QPixmap m_sprite;
  Sizes m_size;
  int m_xoffset;
  int m_xvelocity;
  int m_currentframe;
  int m_animationframes;

};

#endif // STICKMAN_H
