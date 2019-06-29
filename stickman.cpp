#include "stickman.h"

stickman::stickman(Sizes size, const QPixmap& image):
  m_sprite(image),
  m_size(size),
  m_xoffset(0),
  m_xvelocity(0),
  m_currentframe(0) {

}

stickman::~stickman() = default;

void stickman::render(QPainter& painter) {
  /* get the y position so the sprite stays on the ground for all sizes
   * 100 is hardcoded value for this specific background
   * so the sprite is on the ground not at the bottom of screen */
  int yPostion = painter.device()->height() - getHeight() - 100;

  // calculate how much to scale the sprite to match the bounding box of stickman
  // basically get the ratio for scaling
  int scaleX = getWidth() / getSprite().width();
  int scaleY = getHeight() / getSprite().height();

  // pass in additional parameter for sprite sheet animation
  painter.drawPixmap(m_xoffset, yPostion, getSprite().transformed(QTransform().scale(scaleX, scaleY)),
                     m_currentframe, 0, getAnimationBlock() * getSize(), getAnimationBlock() * getSize());
}

QPixmap stickman::getSprite() {
  return m_sprite;
}

void stickman::setXoffset(int value) {
  m_xoffset = value;
}

void stickman::setVelocity(int value) {
  m_xvelocity = value;
}

int stickman::getVelocity() {
  return m_xvelocity;
}

int stickman::getSize() {
  if(m_size == Tiny) {
    return 1;
  }
  if(m_size == Normal) {
    return 2;
  }
  if(m_size == Large) {
    return 3;
  }
  if(m_size == Giant) {
    return 4;
  }
  return 1;
}

int stickman::getNumberOfAnimationFrames() {
  return m_animationframes;
}

void stickman::setNumberOfAnimationFrames(int numFrames) {
  m_animationframes = numFrames;
}

int stickman::getAnimationBlock() {
  // total width of sprite sheet divide by number of frames
  // hopefully each sprite is equally space
  // requires basic understanding of how sprite sheet works
  return getSprite().width() / getNumberOfAnimationFrames();
}

void stickman::nextFrame() {
  // this move the frame to next sprite
  m_currentframe += getAnimationBlock() * getSize();
  // if it reach the end of sprite sheet rewind back to start
  if (m_currentframe >= getSprite().width() * getSize() ) {
    m_currentframe = 0;
  }
}
