#include "Object.h"

using namespace std;

string Object::getObjectType() {
    return objectType;
}

Coordinates Object::getMapLocation() {
    return mapLocation;
}

void Object::setObjectType(string newObjectType) {
    objectType = newObjectType;
}

void Object::setMapLocation(Coordinates newCoords) {
    mapLocation = newCoords;
}