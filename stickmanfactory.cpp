#include "stickmanfactory.h"
#include "tinystickman.h"
#include "normalstickman.h"
#include "largestickman.h"
#include "giantstickman.h"

stickman* stickmanfactory::produce(const string& size, const QPixmap& sprite) {
  // produce stickman base on the size given
  if(size == "tiny") {
    return new tinystickman(sprite);
  }
  if(size == "normal") {
    return new normalstickman(sprite);
  }
  if(size == "large") {
    return new largestickman(sprite);
  }
  if(size == "giant") {
    return new giantstickman(sprite);
  }
  return nullptr;
}
