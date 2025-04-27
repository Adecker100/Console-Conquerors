#include "Cursor.h"

Cursor::Cursor() {
    setObjectType("Cursor");
    screenLocation = { 71,29 };
    setMapLocation({ 73,20 });
}

Coordinates Cursor::getScreenLocation() {
    return screenLocation;
}

void Cursor::setScreenLocation(Coordinates newScreenLocation) {
    screenLocation = newScreenLocation;
}