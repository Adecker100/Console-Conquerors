#pragma once
#include "Cursor.h"
#include "DisplayV2.h"
#include "Unit.h"
#include "Tower.h"
#include <chrono>

using namespace std::chrono;

class Game {
public:
	void startGame();
	void titleScreen();
	void diffSelect();
	void instructMenu();
	void instructQuickStart();
	void instructUnits();
	void instructTowers();
	void instructCursorMap();
	void loadGame();
	void saveGame();
	void genMap();
	void renderOverlay();
	void winGame();
	void loseGame();
	void renderUnitBar();
	char checkForInput();
	char waitForInput();
	void unitAction(Unit*);
	void towerAction(Tower*);
	void vectorLoop();
	void moveViewer();
	void moveCursor();
	void enemySpawn();
private:
	string difficulty;
	string selectedUnit;
	DisplayV2 display1;
	vector<Object*> objectVector;
};

