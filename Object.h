#pragma once

#include <stdexcept>
#include <string>

using namespace std;

struct Coordinates {
    int x;
    int y;
};

class Object {
public:
    string getObjectType();
    Coordinates getMapLocation();
    void setObjectType(string);
    void setMapLocation(Coordinates);
private:
    string objectType;
    Coordinates mapLocation;
};