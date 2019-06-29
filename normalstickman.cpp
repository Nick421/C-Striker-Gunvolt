#include "normalstickman.h"

normalstickman::normalstickman(const QPixmap& sprite):
  stickman (Normal, sprite),
  m_scale(2) {

}

normalstickman::~normalstickman() = default;

int normalstickman::getWidth() {
  return getSprite().width() * m_scale;
}

int normalstickman::getHeight() {
  return getSprite().height() * m_scale;
}
