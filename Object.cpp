#include "Object.h"

using namespace std;

string Object::getObjectType() {
    return objectType;
}

Coordinates Object::getMapLocation() {
    return mapLocation;
}

float Object::getHealth() {
    return health;
}

bool Object::getEnemy() {
    return enemy;
}

void Object::setHealth(float newHealth) {
    health = newHealth;
}

void Object::setEnemy(bool newEnemy) {
    enemy = newEnemy;
}

void Object::setObjectType(string newObjectType) {
    objectType = newObjectType;
}

void Object::setMapLocation(Coordinates newCoords) {
    mapLocation = newCoords;
}