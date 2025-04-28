#include "DisplayV2.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

DisplayV2::DisplayV2() {
	screenWidth = 150;
	screenHeight = 50;
	mapWidth = 0;
	mapHeight = 0;
	viewer.x = 0;
	viewer.y = 0;
	screenBuffer.resize(screenWidth);
	previousFrame.resize(screenWidth);


	for (int x = 0; x < screenBuffer.size(); x++) {
		screenBuffer.at(x).resize(screenHeight, Pixel{ '+', 15 });
		previousFrame.at(x).resize(screenHeight, Pixel{ ' ', 15 });
	}
}

DisplayV2::DisplayV2(int newScreenWidth, int newScreenHeight) {
	screenWidth = newScreenWidth;
	screenHeight = newScreenHeight;
	mapWidth = 0;
	mapHeight = 0;
	viewer.x = 0;
	viewer.y = 0;
	screenBuffer.resize(screenWidth);
	previousFrame.resize(screenWidth);

	for (int x = 0; x < screenBuffer.size(); x++) {
		screenBuffer.at(x).resize(screenHeight, Pixel{ '+', 15 });
		previousFrame.at(x).resize(screenHeight, Pixel{ ' ', 15 });
	}
}

void DisplayV2::addGraphic(int graphicX, int graphicY, string fileName, int graphicColor) {

	if (!(graphicX >= 0 && graphicY >= 0)) {
		throw runtime_error("addGraphic command incorrect, graphicX: " + to_string(graphicX) + " graphicY: " + to_string(graphicY));
	}

	int graphicWidth;
	int graphicHeight;

	ifstream fileInput;

	fileInput.open(fileName);

	if (!fileInput.is_open()) {
		throw runtime_error("Graphic file not found: " + fileName);
	}

	fileInput >> graphicWidth >> graphicHeight;

	if (!(graphicWidth > 0 && graphicHeight > 0)) {
		throw runtime_error("Graphic file header incorrect, graphicWidth: " + to_string(graphicWidth) + " graphicHeight: " + to_string(graphicHeight));
	}

	char tempChar;

	for (int y = graphicY; y < (graphicY + graphicHeight); y++) {
		for (int x = graphicX; x < (graphicX + graphicWidth); x++) {
			tempChar = fileInput.get();
			if (tempChar == '\n') {
				tempChar = fileInput.get();
			}
			if (tempChar != ' ') {
				screenBuffer.at(x).at(y).character = tempChar;
				screenBuffer.at(x).at(y).color = graphicColor;
			}
		}
	}
}

void DisplayV2::addString(int stringX, int stringY, string inputString, int stringColor) {
	for (int x = 0; x < inputString.size(); x++) {
		screenBuffer.at(stringX + x).at(stringY).character = inputString[x];
		screenBuffer.at(stringX + x).at(stringY).color = stringColor;
	}
}

void DisplayV2::addMapGraphic(int graphicX, int graphicY, string fileName, int graphicColor) {

	if (!(graphicX >= 0 && graphicY >= 0)) {
		throw runtime_error("addMapGraphic command incorrect, graphicX: " + to_string(graphicX) + " graphicY: " + to_string(graphicY));
	}

	int graphicWidth;
	int graphicHeight;

	ifstream fileInput;

	fileInput.open(fileName);

	if (!fileInput.is_open()) {
		throw runtime_error("Graphic file not found: " + fileName);
	}

	fileInput >> graphicWidth >> graphicHeight;

	if (!(graphicWidth > 0 && graphicHeight > 0)) {
		throw runtime_error("Graphic file header incorrect, graphicWidth: " + to_string(graphicWidth) + " graphicHeight: " + to_string(graphicHeight));
	}

	char tempChar;

	for (int y = graphicY; y < (graphicY + graphicHeight); y++) {
		for (int x = graphicX; x < (graphicX + graphicWidth); x++) {
			tempChar = fileInput.get();
			if (tempChar == '\n') {
				tempChar = fileInput.get();
			}
			if (tempChar != ' ') {
				map.at(x).at(y).character = tempChar;
				map.at(x).at(y).color = graphicColor;
			}
		}
	}
}

void DisplayV2::addMapString(int stringX, int stringY, string inputString, int stringColor) {
	for (int x = 0; x < inputString.size(); x++) {
		map.at(stringX + x).at(stringY).character = inputString[x];
		map.at(stringX + x).at(stringY).color = stringColor;
	}
}

void DisplayV2::drawScreen() {
	for (int y = 0; y < screenHeight; y++) {
		for (int x = 0; x < screenWidth; x++) {
			if (screenBuffer.at(x).at(y).character != previousFrame.at(x).at(y).character || screenBuffer.at(x).at(y).color != previousFrame.at(x).at(y).color) {
				setConCurPosition(x, y, screenBuffer.at(x).at(y).color);
				cout << screenBuffer.at(x).at(y).character;
			}
		}
	}
	for (int y = 0; y < screenHeight; y++) {
		for (int x = 0; x < screenWidth; x++) {
			previousFrame.at(x).at(y) = screenBuffer.at(x).at(y);
		}
	}
}

void DisplayV2::addBorder(char borderChar, int borderColor) {
	for (int y = 0; y < screenHeight; y++) {
		for (int x = 0; x < screenWidth; x++) {
			if (y == 0 || y == (screenHeight - 1)) {
				screenBuffer.at(x).at(y).character = borderChar;
				screenBuffer.at(x).at(y).color = borderColor;
			}
			if (x == 0 || x == (screenWidth - 1)) {
				screenBuffer.at(x).at(y).character = borderChar;
				screenBuffer.at(x).at(y).color = borderColor;
			}
		}
	}
}

void DisplayV2::clearScreen() {
	clearScreenBuffer();
	drawScreen();
}

void DisplayV2::clearScreenBuffer() {
	for (int x = 0; x < screenBuffer.size(); x++) {
		for (int y = 0; y < screenBuffer.at(x).size(); y++) {
			screenBuffer.at(x).at(y) = Pixel{ ' ', 15 };
		}
	}
}

void DisplayV2::clearMap() {
	for (int x = 0; x < map.size(); x++) {
		for (int y = 0; y < map.at(x).size(); y++) {
			map.at(x).at(y) = Pixel{ '#', 2 };
		}
	}
}

void DisplayV2::setViewer(Coordinates newCoords) {
	viewer.x = newCoords.x;
	viewer.y = newCoords.y;
}

void DisplayV2::setMapSize(int newMapWidth, int newMapHeight) {
	mapWidth = newMapWidth;
	mapHeight = newMapHeight;
	map.resize(newMapWidth);
	for (int x = 0; x < map.size(); x++) {
		map.at(x).resize(newMapHeight, Pixel{ '#', 2 });
	}
}

void DisplayV2::renderViewer() {
	for (int y = 10; y < screenHeight; y++) {
		for (int x = 0; x < screenWidth; x++) {
			screenBuffer.at(x).at(y) = map.at(x + viewer.x).at((y - 10) + viewer.y);
		}
	}
}

Coordinates DisplayV2::getMapSize() {
	Coordinates mapSize = { mapWidth,mapHeight };
	return mapSize;
}

Coordinates DisplayV2::getViewerCoords() {
	return viewer;
}

void DisplayV2::setConCurPosition(int conX, int conY, int conColor) {
	if (!(conX >= 0 && conY >= 0 && conX < screenWidth && conY < screenHeight)) {
		throw runtime_error("Console cursor position out of range, x:" + to_string(conX) + " y:" + to_string(conY));
	}

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	if (console == INVALID_HANDLE_VALUE || console == NULL) {
		throw runtime_error("Console handle is invalid!");
	}

	COORD conCoords = { static_cast<SHORT>(conX), static_cast<SHORT>(conY) };
	SetConsoleTextAttribute(console, conColor);
	SetConsoleCursorPosition(console, conCoords);
}