#include "Cursor.h"

Coordinates Cursor::getScreenLocation() {
    return screenLocation;
}

void Cursor::setScreenLocation(Coordinates newScreenLocation) {
    screenLocation = newScreenLocation;
}