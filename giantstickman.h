#ifndef GIANTSTICKMAN_H
#define GIANTSTICKMAN_H

#include "stickman.h"

class giantstickman : public stickman {
 public:
  giantstickman(const QPixmap& sprite);
  ~giantstickman();

  virtual int getWidth();
  virtual int getHeight();

 private:
  int m_scale;
};

#endif // GIANTSTICKMAN_H
