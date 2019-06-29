#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdlib.h>

class Coordinate {
 public:
  Coordinate(
    int xcoordinate,
    int ycoordinate,
    int frameheight,
    int framewidth);

  int getQtRenderingXCoordinate();
  int getQtRenderingYCoordinate();

  void setXCoord(int change);
  void setYCoord(int change);

  void changeInXCoordinate(int change);
  void changeInYCoordinate(int change);

  void setYCoordinateToZero(int offset);

  int getFrameHeight();
  int getFrameWidth();

 private:
  int m_xcoordinate;
  int m_ycoordinate;
  int m_frameheight;
  int m_framewidth;
};

#endif // COORDINATE_H
