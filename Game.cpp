#include "Game.h"
#include <conio.h>
#include <random>
#include <cmath>


void Game::startGame() {
	display1.drawScreen();
	display1.clearScreen();
	display1.addString(0, 0, "Please maximize the console window, then press any key to continue...", 15);
	display1.drawScreen();
	waitForInput();
	display1.clearScreen();
	display1.addString(5, 5, "Welcome to the game! If you are on Windows 11, please enter your console settings.", 15);
	display1.drawScreen();
	display1.addString(5, 7, "Ensure you are running the \"Windows Console Host\" rather than the default \"Windows Terminal\"", 15);
	display1.drawScreen();
	display1.addString(5, 20, "Use the arrow keys and the Enter key to interact with menus", 15);
	display1.drawScreen();
	display1.addString(5, 25, "Press any key to continue...", 15);
	display1.drawScreen();
	waitForInput();
	display1.clearScreen();
	display1.addBorder('#', 15);
	display1.drawScreen();
	for (int i = 0; i < 11; i++) {
		display1.addGraphic(18, i, "Title.txt", 10);
		display1.addBorder('#', 15);
		display1.drawScreen();
		display1.clearScreenBuffer();
	}
	display1.addBorder('#', 15);
	display1.addGraphic(18, 10, "Title.txt", 10);
	display1.addString(60, 34, "Press any key to continue...", 15);
	display1.addString(5, 46, "Console Conquerors! written by Alex Decker 2025", 15);
	display1.drawScreen();
	waitForInput();
	display1.clearScreenBuffer();
	display1.addGraphic(18, 10, "Title.txt", 10);
	for (int i = 10; i > 5; i--) {
		display1.addGraphic(18, i, "Title.txt", 10);
		display1.addBorder('#', 15);
		display1.drawScreen();
		display1.clearScreenBuffer();
	}
	display1.addBorder('#', 15);
	display1.addGraphic(18, 5, "Title.txt", 10);
	display1.drawScreen();
	titleScreen();
}

void Game::titleScreen() {
	char ch = ' ';
	int status = 1;
	display1.clearScreenBuffer();
	display1.addBorder('#', 15);
	display1.addGraphic(18, 5, "Title.txt", 10);
	display1.addGraphic(48, 24, "newGame.txt", 14);
	display1.addGraphic(46, 32, "loadGame.txt", 15);
	display1.addGraphic(39, 40, "instructions.txt", 15);
	display1.drawScreen();
	while (true) {
		ch = waitForInput();
		if (ch == 'v') {
			status = status + 1;
			if (status >= 3) {
				status = 3;
			}
		}
		if (ch == '^') {
			status = status - 1;
			if (status <= 1) {
				status = 1;
			}
		}
		if (ch == '\n') {
			if (status == 1) {
				diffSelect();
				break;
			}
			if (status == 2) {
				loadGame();
			}
			if (status == 3) {
				instructMenu();
			}
		}
		if (status == 1) {
			display1.addGraphic(48, 24, "newGame.txt", 14);
			display1.addGraphic(46, 32, "loadGame.txt", 15);
			display1.addGraphic(39, 40, "instructions.txt", 15);
			display1.drawScreen();
		}
		if (status == 2) {
			display1.addGraphic(48, 24, "newGame.txt", 15);
			display1.addGraphic(46, 32, "loadGame.txt", 14);
			display1.addGraphic(39, 40, "instructions.txt", 15);
			display1.drawScreen();
		}
		if (status == 3) {
			display1.addGraphic(48, 24, "newGame.txt", 15);
			display1.addGraphic(46, 32, "loadGame.txt", 15);
			display1.addGraphic(39, 40, "instructions.txt", 14);
			display1.drawScreen();
		}
	}
}

void Game::diffSelect() {
	char ch = ' ';
	int status = 1;
	display1.clearScreenBuffer();
	display1.addBorder('#', 15);
	display1.addGraphic(41, 3, "newGameHeader.txt", 10);
	display1.addGraphic(18, 10, "selectDifficulty.txt", 10);
	display1.addGraphic(15, 21, "easy.txt", 2);
	display1.addGraphic(15, 30, "medium.txt", 15);
	display1.addGraphic(15, 35, "hard.txt", 15);
	display1.drawScreen();
	while (true) {
		ch = waitForInput();
		if (ch == 'v') {
			status = status + 1;
			if (status >= 3) {
				status = 3;
			}
		}
		if (ch == '^') {
			status = status - 1;
			if (status <= 1) {
				status = 1;
			}
		}
		if (ch == '\n') {
			if (status == 1) {
				difficulty = "Easy";
				genMap();
			}
			if (status == 2) {
				difficulty = "Medium";
				genMap();
			}
			if (status == 3) {
				difficulty = "Hard";
				genMap();
			}
		}
		if (status == 1) {
			display1.addBorder('#', 2);
			display1.addGraphic(15, 21, "easy.txt", 2);
			display1.addGraphic(15, 30, "medium.txt", 15);
			display1.addGraphic(15, 35, "hard.txt", 15);
			display1.drawScreen();
		}
		if (status == 2) {
			display1.addBorder('#', 14);
			display1.addGraphic(15, 21, "easy.txt", 15);
			display1.addGraphic(15, 30, "medium.txt", 14);
			display1.addGraphic(15, 35, "hard.txt", 15);
			display1.drawScreen();
		}
		if (status == 3) {
			display1.addBorder('#', 12);
			display1.addGraphic(15, 21, "easy.txt", 15);
			display1.addGraphic(15, 30, "medium.txt", 15);
			display1.addGraphic(15, 35, "hardSelected.txt", 12);
			display1.drawScreen();
		}
	}
}

void Game::instructMenu() {

}

void Game::instructQuickStart() {

}

void Game::instructUnits() {

}

void Game::instructTowers() {

}

void Game::instructCursorMap() {

}

void Game::loadGame() {

}

void Game::saveGame() {

}

void Game::genMap() {
	int numTowers = 0;
	objectVector.push_back(new Cursor);
	if (difficulty == "Easy") {
		display1.setMapSize(300, 100);
		numTowers = 50;
	}
	if (difficulty == "Medium") {
		display1.setMapSize(600, 300);
		numTowers = 100;
	}
	if (difficulty == "Hard") {
		display1.setMapSize(900, 900);
		numTowers = 200;
	}
	spawnStartingTowers();
	for (int i = 0; i < numTowers; i++) {
		spawnTower();
	}
}

void Game::spawnStartingTowers() {
	Coordinates mapSize = display1.getMapSize();

	//Spawn friendly Towers
	objectVector.push_back(new Tower("Castle", { 12, (mapSize.y / 2) }));
	objectVector.push_back(new Tower("Tower", { 12, ((mapSize.y / 2) + 12) }));
	objectVector.push_back(new Tower("Tower", { 12, ((mapSize.y / 2) - 12) }));


	//Spawn enemy Towers
	objectVector.push_back(new Tower("Castle", { (mapSize.x - 12), (mapSize.y / 2) }));
	objectVector.push_back(new Tower("Tower", { (mapSize.x - 12), ((mapSize.y / 2) + 12) }));
	objectVector.push_back(new Tower("Tower", { (mapSize.x - 12), ((mapSize.y / 2) - 12) }));
}

void Game::spawnTower() {
	Coordinates mapSize = display1.getMapSize();
	random_device seed;
	mt19937 gen(seed());
	uniform_int_distribution<int> xRange(0, mapSize.x);
	uniform_int_distribution<int> yRange(0, mapSize.y);
	uniform_int_distribution<int> probRange(1, 10);

	Coordinates newTowerCoords = { xRange(gen),yRange(gen) };

	int prob = probRange(gen);

	if (difficulty == "Easy") {
		if (prob <= 3) { objectVector.push_back(new Tower("Fortified Position", newTowerCoords)); }
		else {
			if (prob >= 7) { objectVector.push_back(new Tower("Tower", newTowerCoords)); }
			else { objectVector.push_back(new Tower("Fort", newTowerCoords)); }}
	}
	if (difficulty == "Medium") {
		if (prob <= 5) { objectVector.push_back(new Tower("Fortified Position", newTowerCoords)); }
		else {
			if (prob >= 9) { objectVector.push_back(new Tower("Tower", newTowerCoords)); }
			else { objectVector.push_back(new Tower("Fort", newTowerCoords)); }
		}
	}
	if (difficulty == "Hard") {
		if (prob <= 7) { objectVector.push_back(new Tower("Fortified Position", newTowerCoords)); }
		else {
			if (prob == 10) { objectVector.push_back(new Tower("Tower", newTowerCoords)); }
			else { objectVector.push_back(new Tower("Fort", newTowerCoords)); }
		}
	}

	Tower* towerPtr = dynamic_cast<Tower*>(objectVector.at(objectVector.size() - 1));
	bool tooClose = true;
	int xTowerRange = towerPtr->getTowerWidth() * 2;
	int yTowerRange = towerPtr->getTowerHeight() * 2;

	while (tooClose) {
		tooClose = false;
		if (newTowerCoords.x < xTowerRange || (mapSize.x - newTowerCoords.x) < xTowerRange) {
			tooClose = true;
		}
		else if (newTowerCoords.y < yTowerRange || (mapSize.y - newTowerCoords.y) < yTowerRange) {
			tooClose = true;
		}
		else {
			for (int i = 0; i < objectVector.size(); i++) {
				Tower* loopTowerPtr = dynamic_cast<Tower*>(objectVector.at(i));
				int badLowRangeX = loopTowerPtr->getMapLocation().x - (loopTowerPtr->getTowerWidth() * 2);
				int badHighRangeX = loopTowerPtr->getMapLocation().x + (loopTowerPtr->getTowerWidth() * 2);
				int badLowRangeY = loopTowerPtr->getMapLocation().y - (loopTowerPtr->getTowerHeight() * 2);
				int badHighRangeY = loopTowerPtr->getMapLocation().y + (loopTowerPtr->getTowerHeight() * 2);
				if (loopTowerPtr != towerPtr) {
					if (newTowerCoords.x > badLowRangeX && newTowerCoords.x < badHighRangeX) {
						tooClose = true;
					}
					else if (newTowerCoords.y > badLowRangeY && newTowerCoords.y < badHighRangeY) {
						tooClose = true;
					}
				}
			}
		}
		if (tooClose) {
			newTowerCoords = { xRange(gen),yRange(gen) };
		}
	}
}

void Game::mainLoop() {

}

void Game::renderOverlay(Object* objectPtr) {

}

void Game::winGame() {

}

void Game::loseGame() {

}

void Game::renderUnitBar() {

}

char Game::checkForInput() {
	if (_kbhit()) {
		int ch = _getch();

		if (ch == 0 || ch == 224) {
			int specialKey = _getch();

			switch (specialKey) {
			case 72: return '^';
			case 80: return 'v';
			case 75: return '<';
			case 77: return '>';
			default: return '?';
			}
		}

		if (ch == 13) {
			return '\n';
		}

		while (_kbhit()) _getch();

		return static_cast<char>(ch);
	}
}

char Game::waitForInput() {
	int ch = _getch();

	if (ch == 0 || ch == 224) {
		int specialKey = _getch();

		switch (specialKey) {
		case 72: return '^';
		case 80: return 'v';
		case 75: return '<';
		case 77: return '>';
		default: return '?';
		}
	}

	if (ch == 13) {
		return '\n';
	}

	return static_cast<char>(ch);
}

void Game::unitAction(Unit* unitPtr) {

	if (unitPtr->getHealth() <= 0) {
		if (unitPtr->getAlive()) {
			unitPtr->setAlive(false);
			random_device seed;
			mt19937 gen(seed());
			uniform_int_distribution<int> prob(1, 2);
			display1.addMapString(unitPtr->getMapLocation().x, unitPtr->getMapLocation().y, "#", (prob(gen) * 2));
		}
	}
	else {
		bool canAttack = false;
		for (int i = 0; i < objectVector.size(); i++) {
			if (objectVector.at(i)->getEnemy() != unitPtr->getEnemy()) {
				if (abs(objectVector.at(i)->getMapLocation().x - unitPtr->getMapLocation().x) <= unitPtr->getAttackRange()) {
					if (abs(objectVector.at(i)->getMapLocation().y - unitPtr->getMapLocation().y) <= (unitPtr->getAttackRange() / 2)) {
						canAttack = true;
					}
				}
			}
		}
		if (canAttack) {
			if ((steady_clock::now() - unitPtr->getLastAttackTime()) >= unitPtr->getAttackSpeed()) {
				Object* closestEnemy = nullptr;
				float closestEnemyDist = 100.0;
				float enemyDist = 0.0;
				float enemyXDist = 0.0;
				float enemyYDist = 0.0;
				for (int i = 0; i < objectVector.size(); i++) {
					if (objectVector.at(i)->getEnemy() != unitPtr->getEnemy()) {
						if (abs(objectVector.at(i)->getMapLocation().x - unitPtr->getMapLocation().x) <= unitPtr->getAttackRange()) {
							if (abs(objectVector.at(i)->getMapLocation().y - unitPtr->getMapLocation().y) <= (unitPtr->getAttackRange() / 2)) {
								enemyXDist = abs(objectVector.at(i)->getMapLocation().x - unitPtr->getMapLocation().x);
								enemyYDist = abs(objectVector.at(i)->getMapLocation().y - unitPtr->getMapLocation().y) / 2;
								enemyDist = sqrt((enemyXDist * enemyXDist) + (enemyYDist * enemyYDist));
								if (enemyDist < closestEnemyDist) {
									closestEnemyDist = enemyDist;
									closestEnemy = objectVector.at(i);
								}
							}
						}
					}
				}
			}
		}
		else {
			if ((steady_clock::now() - unitPtr->getLastMoveTime()) >= unitPtr->getMoveSpeed()) {
				Coordinates unitPosition = unitPtr->getMapLocation();
				if (unitPtr->getEnemy()) {
					unitPosition.x--;
				}
				else {
					unitPosition.x++;
				}
				unitPtr->setMapLocation(unitPosition);
				unitPtr->setLastMoveTime(steady_clock::now());
			}
		}
	}
}

void Game::towerAction(Tower* towerPtr) {

}

void Game::actionLoop() {
	for (int i = 0; i < objectVector.size(); i++) {
		if (objectVector.at(i)->getObjectType() == "Unit") {
			Unit* unitPtr = dynamic_cast<Unit*>(objectVector.at(i));
			unitAction(unitPtr);
		}
		else if (objectVector.at(i)->getObjectType() == "Tower") {
			Tower* towerPtr = dynamic_cast<Tower*>(objectVector.at(i));
			towerAction(towerPtr);
		}
	}
	cursorAction();
}

void Game::moveViewer() {
	char ch = checkForInput();
	Coordinates viewerCoords = display1.getViewerCoords();
	Coordinates cursorCoords = cursor1.getMapLocation();

	if (toupper(ch) == 'W') {
		if (display1.getViewerCoords().y >= 0) {
			viewerCoords.y--;
			cursorCoords.y--;
		}
	}
	if (toupper(ch) == 'S') {
		if (display1.getViewerCoords().y < (display1.getMapSize().y - 40)) {
			viewerCoords.y++;
			cursorCoords.y++;
		}
	}
	if (toupper(ch) == 'A') {
		if (display1.getViewerCoords().x >= 0) {
			viewerCoords.x--;
			cursorCoords.x--;
		}
	}
	if (toupper(ch) == 'D') {
		if (display1.getViewerCoords().x < (display1.getMapSize().x - 150)) {
			viewerCoords.x++;
			cursorCoords.x++;
		}
	}

	display1.setViewer(viewerCoords);
	cursor1.setMapLocation(cursorCoords);
}

void Game::cursorAction() {
	char ch = checkForInput();
	Coordinates cursorScreenLocation = cursor1.getScreenLocation();
	Coordinates cursorMapLocation = cursor1.getMapLocation();

	if (ch == '^') {
		if (cursor1.getScreenLocation().y > 11) {
			cursorScreenLocation.y--;
			cursorMapLocation.y--;
		}
	}
	if (ch == 'v') {
		if (cursor1.getScreenLocation().y < 48) {
			cursorScreenLocation.y++;
			cursorMapLocation.y++;
		}
	}
	if (ch == '<') {
		if (cursor1.getScreenLocation().x > 2) {
			cursorScreenLocation.x--;
			cursorMapLocation.x--;
		}
	}
	if (ch == '>') {
		if (cursor1.getScreenLocation().x < 148) {
			cursorScreenLocation.x++;
			cursorMapLocation.x++;
		}
	}

	cursor1.setScreenLocation(cursorScreenLocation);
	cursor1.setMapLocation(cursorMapLocation);
	display1.addMapGraphic((cursorMapLocation.x - 2), (cursorMapLocation.y - 1), "cursor.txt", 12);
}

void Game::enemySpawn() {

}
