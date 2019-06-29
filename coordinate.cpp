#include "coordinate.h"

Coordinate::Coordinate(int xcoordinate,
                       int ycoordinate,
                       int frameheight,
                       int framewidth)
  : m_xcoordinate(xcoordinate)
  , m_ycoordinate(ycoordinate)
  , m_frameheight(frameheight)
  , m_framewidth(framewidth)

{

}

int Coordinate::getQtRenderingXCoordinate() {
  return static_cast<int>(m_xcoordinate);
}

int Coordinate::getQtRenderingYCoordinate() {
  return m_frameheight - m_ycoordinate;
}

void Coordinate::setXCoord(int change) {
  m_xcoordinate = change;
}

void Coordinate::setYCoord(int change) {
  m_ycoordinate = change;
}

void Coordinate::changeInXCoordinate(int change) {
  m_xcoordinate += change;
}

void Coordinate::changeInYCoordinate(int change) {
  m_ycoordinate += change;
}

void Coordinate::setYCoordinateToZero(int offset) {
  m_ycoordinate = offset;
}

int Coordinate::getFrameHeight() {
  return m_frameheight;
}

int Coordinate::getFrameWidth() {
  return m_framewidth;
}


