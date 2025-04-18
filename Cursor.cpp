#include "Cursor.h"

Cursor::Cursor() {
    setObjectType("Cursor");
}

Coordinates Cursor::getScreenLocation() {
    return screenLocation;
}

void Cursor::setScreenLocation(Coordinates newScreenLocation) {
    screenLocation = newScreenLocation;
}