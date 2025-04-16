#pragma once

#include "Object.h"

class Cursor : public Object {
public:
    Coordinates getScreenLocation();
    void setScreenLocation(Coordinates);
private:
    Coordinates screenLocation;
};