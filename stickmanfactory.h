#ifndef STICKMANFACTORY_H
#define STICKMANFACTORY_H

#include "stickman.h"

using namespace std;

class stickmanfactory
{
public:
    static stickman* produce(const string& size, const QPixmap& sprite);
    virtual ~stickmanfactory();
};

#endif // STICKMANFACTORY_H
