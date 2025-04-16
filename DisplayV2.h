#pragma once

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
	void clearScreen();
	void clearBuffer();
	void clearMap();
private:
	int screenWidth;
	int screenHeight;
	int mapWidth;
	int mapHeight;
	int viewerX;
	int viewerY;
	vector<vector<Pixel>> map;
	vector<vector<Pixel>> screenBuffer;
	vector<vector<Pixel>> previousFrame;
	void setConsoleCursorPosition(int, int, int);
};

