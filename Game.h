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
	bool isKeyPressed(int);
	bool isNewKeyPress(int);
	char waitForInput();
	void unitAction(Unit*, int);
	void towerAction(Tower*, int);
	void actionLoop();
	void moveViewer();
	void cursorAction();
	void enemySpawn();
	void drawUnitWalk(Unit*);
	void drawUnitAttack(Unit*);
	void spawnUnit(string);
private:
	time_point<steady_clock> lastCursorXMoveTime = steady_clock::now();
	time_point<steady_clock> lastCursorYMoveTime = steady_clock::now();
	time_point<steady_clock> lastEnemySpawnTime = steady_clock::now();
	time_point<steady_clock> lastMoneyTime = steady_clock::now();
	duration<double> enemySpawnSpeed;
	Object* overlayObject = nullptr;
	string difficulty;
	int selectedUnit = 1;
	DisplayV2 display1;
	Cursor cursor1;
	vector<Object*> objectVector;
	int money = 0;
};

