#ifndef LARGESTICKMAN_H
#define LARGESTICKMAN_H

#include "stickman.h"

class largestickman : public stickman {
 public:
  largestickman(const QPixmap& sprite);
  ~largestickman();

  virtual int getWidth();
  virtual int getHeight();

 private:
  int m_scale;
};

#endif // LARGESTICKMAN_H
