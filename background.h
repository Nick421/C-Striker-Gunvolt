#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QPainter>
#include <QPixmap>

#include <cmath>

#include "coordinate.h"

class background {
 public:
  /* construct the background from the image.
   * We tile 2 image, one after the other.
  */
  background(const QPixmap& image);
  ~background();

  // render the background. Velocity is the character speed
  void render(QPainter& painter, int velocity);

  // check if background has goes out of screen
  bool needRepeat();

  void update(int currentTime);

  // set in game time in milliseconds (for day/night cycle)
  void setDaytime(int time);

  // set bound for x in cosine wave (for day/night cycle)
  float bound(float x, float x_min, float x_max);

 private:
  QPixmap m_image;
  QPixmap m_image_tile; // 2nd image for tiling
  Coordinate m_coordinate;
  Coordinate m_coordinate_tile;
  int m_current_time;
  int m_dayduration; // duration of day cycle in game time (for day/night cycle)
};
#endif // BACKGROUND_H
