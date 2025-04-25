#pragma once

#include "Object.h"
#include <vector>
#include <string>

using namespace std;

struct Pixel {
	char character;
	int color;
};

class DisplayV2 {
public:
	DisplayV2();
	DisplayV2(int, int);
	void addGraphic(int, int, string, int);
	void addString(int, int, string, int);
	void addMapGraphic(int, int, string, int);
	void addMapString(int, int, string, int);
	void drawScreen();
	void addBorder(char, int);
	void clearScreen();
	void clearScreenBuffer();
	void clearMap();
	void setViewer(Coordinates);
	void setMapSize(int, int);
	void renderViewer();
	Coordinates getMapSize();
	Coordinates getViewerCoords();
private:
	int screenWidth;
	int screenHeight;
	int mapWidth;
	int mapHeight;
	Coordinates viewer;
	vector<vector<Pixel>> map;
	vector<vector<Pixel>> screenBuffer;
	vector<vector<Pixel>> previousFrame;
	void setConCurPosition(int, int, int);
};

