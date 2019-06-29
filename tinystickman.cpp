#include "tinystickman.h"

tinystickman::tinystickman(const QPixmap& sprite):
  stickman (Tiny, sprite),
  m_scale(1) {

}

tinystickman::~tinystickman() = default;

int tinystickman::getWidth() {
  return getSprite().width() * m_scale;
}

int tinystickman::getHeight() {
  return getSprite().height() * m_scale;
}
