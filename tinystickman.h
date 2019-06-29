#ifndef TINYSTICKMAN_H
#define TINYSTICKMAN_H

#include "stickman.h"

class tinystickman : public stickman {
 public:
  tinystickman(const QPixmap& sprite);
  ~tinystickman();

  virtual int getWidth();
  virtual int getHeight();

 private:
  int m_scale;
};

#endif // TINYSTICKMAN_H
