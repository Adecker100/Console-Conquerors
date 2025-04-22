#pragma once
#include "Cursor.h"
#include "DisplayV2.h"
#include "Unit.h"
#include "Tower.h"
#include <chrono>

using namespace std::chrono;

class Game {
public:
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
	void infoOverlay();
	void winGame();
	void loseGame();
	void unitBar();
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

