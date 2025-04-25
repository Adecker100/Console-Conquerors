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
    virtual string getObjectType();
    Coordinates getMapLocation();
    float getHealth();
    bool getEnemy();
    void setHealth(float);
    void setEnemy(bool);
    void setObjectType(string);
    void setMapLocation(Coordinates);
private:
    float health;
    bool enemy = false;
    string objectType;
    Coordinates mapLocation;
};