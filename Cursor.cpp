#include "Cursor.h"

Cursor::Cursor() {
    setObjectType("Cursor");
    screenLocation = { 75,30 };
}

Coordinates Cursor::getScreenLocation() {
    return screenLocation;
}

void Cursor::setScreenLocation(Coordinates newScreenLocation) {
    screenLocation = newScreenLocation;
}