#include "giantstickman.h"

giantstickman::giantstickman(const QPixmap& sprite):
  stickman (Giant, sprite),
  m_scale(4) {

}

giantstickman::~giantstickman() = default;

int giantstickman::getWidth() {
  return getSprite().width() * m_scale;
}

int giantstickman::getHeight() {
  return getSprite().height() * m_scale;
}

