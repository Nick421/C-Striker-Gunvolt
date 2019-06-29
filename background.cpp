#include "background.h"

using namespace std;

background::background(const QPixmap& image)
  : m_image(image),
    m_image_tile(image),
    m_coordinate(Coordinate(0, 0, image.height(), image.width())),
    m_coordinate_tile(Coordinate(image.width(), 0, image.height(), image.width())),
    m_current_time(0),
    m_dayduration(60000) {

}

background::~background() = default;

void background::render(QPainter& painter, int velocity) {
  // if one image goes out of bound on the left side of screen, reset it back
  if (needRepeat()) {
    m_coordinate.setXCoord(0);
    m_coordinate_tile.setXCoord(m_coordinate_tile.getFrameWidth());
  }

  // draw the background
  painter.drawPixmap(m_coordinate.getQtRenderingXCoordinate(), 0, m_image);
  painter.drawPixmap(m_coordinate_tile.getQtRenderingXCoordinate(), 0, m_image_tile);

  // set speed of backgrounds
  m_coordinate.changeInXCoordinate(velocity);
  m_coordinate_tile.changeInXCoordinate(velocity);

  // apply day/night filter
  if (m_dayduration) {
    // calculate strength of the filter depending on day progress
    float day_progress = static_cast<float>(m_current_time) / m_dayduration;
    float effect_strength = bound(-cos(day_progress * 3.14f), -0.5f, 0.5f) + 0.7f;

    // draw a rectangle over the background
    // fill it with blue shade depends on effect strength
    QRectF filter(0, 0, painter.device()->width(), painter.device()->height());
    // the RGB and A value is hardcoded but can be change for different effects.
    painter.fillRect(filter, QBrush(QColor(0, 0, static_cast<int>(100 * effect_strength), static_cast<int>(120 * effect_strength))));
  }
}

bool background::needRepeat() {
  return m_coordinate.getQtRenderingXCoordinate() + m_image.width() <= 0;
}

// bound x to be between min and max
float background::bound(float x, float x_min, float x_max) {
  return min(x_max, max(x, x_min));
}

void background::update(int currentTime) {
  m_current_time += currentTime;
}

void background::setDaytime(int time) {
  m_dayduration = time;
}
