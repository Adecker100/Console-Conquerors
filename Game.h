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
	void spawnStartingTowers();
	void spawnTower();
	void mainLoop();
	void renderOverlay();
	void checkCursor(Object*);
	void winGame();
	void loseGame();
	void renderUnitBar();
	char checkForInput();
	char waitForInput();
	void unitAction(Unit*);
	void towerAction(Tower*);
	void actionLoop();
	void moveViewer();
	void cursorAction();
	void enemySpawn();
private:
	time_point<steady_clock> lastEnemySpawnTime = steady_clock::now();
	duration<double> enemySpawnSpeed;
	Object* overlayObject = nullptr;
	string difficulty;
	string selectedUnit;
	DisplayV2 display1;
	Cursor cursor1;
	vector<Object*> objectVector;
};

