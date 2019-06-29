#include "largestickman.h"

largestickman::largestickman(const QPixmap& sprite):
  stickman (Large, sprite),
  m_scale(3) {

}

largestickman::~largestickman() = default;

int largestickman::getWidth() {
  return getSprite().width() * m_scale;
}

int largestickman::getHeight() {
  return getSprite().height() * m_scale;
}

