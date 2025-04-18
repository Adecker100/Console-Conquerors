#pragma once

#include "Object.h"

class Cursor : public Object {
public:
    Cursor();
    Coordinates getScreenLocation();
    void setScreenLocation(Coordinates);
private:
    Coordinates screenLocation;
};