#ifndef NORMALSTICKMAN_H
#define NORMALSTICKMAN_H

#include "stickman.h"

class normalstickman : public stickman {
 public:
  normalstickman(const QPixmap& sprite);
  ~normalstickman();

  virtual int getWidth();
  virtual int getHeight();

 private:
  int m_scale;
};

#endif // NORMALSTICKMAN_H
