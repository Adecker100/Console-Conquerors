#include "Game.h"
#include <conio.h>
#include <random>
#include <cmath>
#include <iostream>
#include <Windows.h>

using namespace std;


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
		display1.addGraphic(41, 3, "newGameHeader.txt", 10);
		display1.addGraphic(18, 10, "selectDifficulty.txt", 10);
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
		display1.clearScreenBuffer();
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
	if (difficulty == "Easy") {
		display1.setMapSize(300, 100);
		enemySpawnSpeed = duration<double>(1.5);
		numTowers = 50;
		money = 50;
	}
	if (difficulty == "Medium") {
		display1.setMapSize(600, 300);
		enemySpawnSpeed = duration<double>(1.0);
		numTowers = 100;
		money = 50;
	}
	if (difficulty == "Hard") {
		display1.setMapSize(900, 900);
		enemySpawnSpeed = duration<double>(0.5);
		numTowers = 200;
		money = 50;
	}

	spawnStartingTowers();
	for (int i = 0; i < numTowers; i++) {
		spawnTower();
	}
	display1.clearScreen();
	mainLoop();
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

	//Generate random coordinates for new tower
	Coordinates newTowerCoords = { xRange(gen),yRange(gen) };

	int prob = probRange(gen);

	//Determine the probability of what type of tower will spawn
	if (difficulty == "Easy") {
		if (prob <= 3) { objectVector.push_back(new Tower("Fortified Position", newTowerCoords)); }
		else {
			if (prob >= 7) { objectVector.push_back(new Tower("Tower", newTowerCoords)); }
			else { objectVector.push_back(new Tower("Fort", newTowerCoords)); }
		}
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
	int xTowerRange = towerPtr->getTowerWidth() * 3;
	int yTowerRange = towerPtr->getTowerHeight() * 3;
	while (tooClose) {
		tooClose = false;

		//Check if tower is too close to x edge of map
		if (newTowerCoords.x < xTowerRange || (mapSize.x - newTowerCoords.x) < xTowerRange) {
			tooClose = true;
		}

		//Check if tower is too close to y edge of map
		else if (newTowerCoords.y < yTowerRange || (mapSize.y - newTowerCoords.y) < yTowerRange) {
			tooClose = true;
		}

		//Check if tower is too close to another tower
		else {
			for (int i = 0; i < objectVector.size(); i++) {
				if (objectVector.at(i)->getObjectType() == "Tower") {
					Tower* loopTowerPtr = dynamic_cast<Tower*>(objectVector.at(i));

					for (int i = 0; i < objectVector.size(); i++) {

						Tower* loopTowerPtr = dynamic_cast<Tower*>(objectVector.at(i));
						int badLowRangeX = loopTowerPtr->getMapLocation().x - ((loopTowerPtr->getTowerWidth() + towerPtr->getTowerWidth()) * 2);
						int badHighRangeX = loopTowerPtr->getMapLocation().x + ((loopTowerPtr->getTowerWidth() + towerPtr->getTowerWidth()) * 2);
						int badLowRangeY = loopTowerPtr->getMapLocation().y - ((loopTowerPtr->getTowerHeight() + towerPtr->getTowerHeight()) * 2);
						int badHighRangeY = loopTowerPtr->getMapLocation().y + ((loopTowerPtr->getTowerHeight() + towerPtr->getTowerHeight()) * 2);

						//Don't check the tower against itself, it will always be too close!
						if (loopTowerPtr != towerPtr) {

							//Check the distance to the other tower
							if (newTowerCoords.x > badLowRangeX && newTowerCoords.x < badHighRangeX && newTowerCoords.y > badLowRangeY && newTowerCoords.y < badHighRangeY) {
								tooClose = true;
							}
						}
					}
				}
			}
		}
		if (tooClose) {
			newTowerCoords = { xRange(gen),yRange(gen) };
		}
	}
	towerPtr->setMapLocation(newTowerCoords);
}

void Game::mainLoop() {
	while (true) {
		display1.clearMap();
		display1.clearScreenBuffer();
		moveViewer();
		actionLoop();
		enemySpawn();
		cursorAction();
		display1.renderViewer();
		renderUnitBar();
		renderOverlay();
		display1.addBorder('#', 15);
		display1.drawScreen();
	}
}

void Game::renderOverlay() {
	if (overlayObject != nullptr) {
		if (overlayObject->getObjectType() == "Tower") {
			Tower* towerPtr = dynamic_cast<Tower*>(overlayObject);
		}
		if (overlayObject->getObjectType() == "Unit") {
			Unit* unitPtr = dynamic_cast<Unit*>(overlayObject);
		}
	}
}

void Game::checkCursor(Object* objectPtr) {
	if (isNewKeyPress(VK_RETURN)) {
		if (abs(objectPtr->getMapLocation().x - cursor1.getMapLocation().x) <= 2) {
			if (abs(objectPtr->getMapLocation().y - cursor1.getMapLocation().y) <= 1) {
				overlayObject = objectPtr;
			}
		}
		else {
			overlayObject = nullptr;
		}
	}
}

void Game::winGame() {

}

void Game::loseGame() {

}

void Game::renderUnitBar() {
	if (steady_clock::now() - lastMoneyTime >= duration<int>(1)) {
		money++;
		lastMoneyTime = steady_clock::now();
	}
	Tower* castlePtr = dynamic_cast<Tower*>(objectVector.at(0));
	display1.addString(83, 4, "Money: " + to_string(money), 10);
	display1.addString(83, 6, "Castle Health", 15);
	display1.addString(84, 7, to_string(static_cast<int>(castlePtr->getHealth())) + " / 2000", 15);
	display1.addGraphic(5, 3, "Sword Guy!unitBar.txt", 15);
	display1.addGraphic(18, 3, "Shield ManunitBar.txt", 15);
	display1.addGraphic(31, 3, "ArcherunitBar.txt", 15);
	display1.addGraphic(44, 3, "BruteunitBar.txt", 15);
	display1.addGraphic(57, 3, "CatapultunitBar.txt", 15);
	display1.addGraphic(70, 3, "EngineerunitBar.txt", 15);
	
	switch (selectedUnit) {
	case 1:
		display1.addGraphic(3, 2, "unitBarBox.txt", 11);
		display1.addString(6, 8, "Cost: 1", 14);
		break;
	case 2:
		display1.addGraphic(16, 2, "unitBarBox.txt", 11);
		display1.addString(19, 8, "Cost: 3", 14);
		break;
	case 3:
		display1.addGraphic(29, 2, "unitBarBox.txt", 11);
		display1.addString(32, 8, "Cost: 2", 14);
		break;
	case 4:
		display1.addGraphic(42, 2, "unitBarBox.txt", 11);
		display1.addString(45, 8, "Cost: 4", 14);
		break;
	case 5:
		display1.addGraphic(55, 2, "unitBarBox.txt", 11);
		display1.addString(58, 8, "Cost: 5", 14);
		break;
	case 6:
		display1.addGraphic(68, 2, "unitBarBox.txt", 11);
		display1.addString(71, 8, "Cost: 4", 14);
		break;
	}

	if (isNewKeyPress('1')) {
		if (selectedUnit == 1) {
			display1.addGraphic(3, 2, "unitBarBox.txt", 14);
			spawnUnit("Sword Guy!");
		}
		selectedUnit = 1;
	}
	if (isNewKeyPress('2')) {
		if (selectedUnit == 2) {
			display1.addGraphic(16, 2, "unitBarBox.txt", 14);
			spawnUnit("Shield Man");
		}
		selectedUnit = 2;
	}
	if (isNewKeyPress('3')) {
		if (selectedUnit == 3) {
			display1.addGraphic(29, 2, "unitBarBox.txt", 14);
			spawnUnit("Archer");
		}
		selectedUnit = 3;
	}
	if (isNewKeyPress('4')) {
		if (selectedUnit == 4) {
			display1.addGraphic(42, 2, "unitBarBox.txt", 14);
			spawnUnit("Brute");
		}
		selectedUnit = 4;
	}
	if (isNewKeyPress('5')) {
		if (selectedUnit == 5) {
			display1.addGraphic(55, 2, "unitBarBox.txt", 14);
			spawnUnit("Catapult");
		}
		selectedUnit = 5;
	}
	if (isNewKeyPress('6')) {
		if (selectedUnit == 6) {
			display1.addGraphic(68, 2, "unitBarBox.txt", 14);
			spawnUnit("Engineer");
		}
		selectedUnit = 6;
	}
}

bool Game::isKeyPressed(int key) {
	if (GetAsyncKeyState(key) & 0x8000) {
		return true;
	}
	else {
		return false;
	}
}

bool Game::isNewKeyPress(int key) {
	if (GetAsyncKeyState(key) & 0x0001) {
		return true;
	}
	else {
		return false;
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

	//If unit is dead, draw the bloody grass 0.0
	if (unitPtr->getHealth() <= 0) {
		if (unitPtr->getAlive()) {
			unitPtr->setAlive(false);
			random_device seed;
			mt19937 gen(seed());
			uniform_int_distribution<int> prob(1, 2);
			unitPtr->setDeadColor(prob(gen) * 2);
			display1.addMapString(unitPtr->getMapLocation().x, unitPtr->getMapLocation().y, "#", unitPtr->getDeadColor());
		}
		else {
			display1.addMapString(unitPtr->getMapLocation().x, unitPtr->getMapLocation().y, "#", unitPtr->getDeadColor());
		}
	}

	//If the unit is not dead...
	else {

		//Check if the unit is in attack range of an enemy
		bool canAttack = false;
		for (int i = 0; i < objectVector.size(); i++) {
			if (objectVector.at(i)->getEnemy() != unitPtr->getEnemy()) {
				if (abs(objectVector.at(i)->getMapLocation().x - unitPtr->getMapLocation().x) <= unitPtr->getAttackRange()) {
					if (abs(objectVector.at(i)->getMapLocation().y - unitPtr->getMapLocation().y) <= (unitPtr->getAttackRange() / 2)) {
						if (objectVector.at(i)->getObjectType() == "Tower") {
							Tower* towerPtr = dynamic_cast<Tower*>(objectVector.at(i));
							if (towerPtr->getNumUnits() > 0) {
								canAttack = true;
							}
						}
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

				//Find out which enemy unit is the closest
				for (int i = 0; i < objectVector.size(); i++) {
					if (objectVector.at(i)->getEnemy() != unitPtr->getEnemy()) {
						if (abs(objectVector.at(i)->getMapLocation().x - unitPtr->getMapLocation().x) <= unitPtr->getAttackRange()) {
							if (abs(objectVector.at(i)->getMapLocation().y - unitPtr->getMapLocation().y) <= (unitPtr->getAttackRange() / 2)) {
								enemyXDist = abs(objectVector.at(i)->getMapLocation().x - unitPtr->getMapLocation().x);
								enemyYDist = abs(objectVector.at(i)->getMapLocation().y - unitPtr->getMapLocation().y) / 2.0;
								enemyDist = sqrt((enemyXDist * enemyXDist) + (enemyYDist * enemyYDist));
								if (enemyDist < closestEnemyDist) {
									closestEnemyDist = enemyDist;
									closestEnemy = objectVector.at(i);
								}
							}
						}
					}
				}
				if (unitPtr->getAttackType() == "Precise") {
					if (closestEnemy->getObjectType() == "Unit") {
						closestEnemy->setHealth(closestEnemy->getHealth() - unitPtr->getAttackDamage());
						unitPtr->setLastAttackTime(steady_clock::now());
					}
					if (closestEnemy->getObjectType() == "Tower") {

					}
				}
				if (unitPtr->getAttackType() == "Area") {

				}
			}
		}

		//If not in attack range of anything, move instead
		else {
			if ((steady_clock::now() - unitPtr->getLastMoveTime()) >= unitPtr->getMoveSpeed()) {
				Coordinates unitPosition = unitPtr->getMapLocation();
				if (unitPtr->getEnemy()) {
					if (unitPosition.x > 12) {
						unitPosition.x--;
					}
					else {
						if (unitPosition.y < (display1.getMapSize().y) / 2) {
							unitPosition.y++;
						}
						else {
							unitPosition.y--;
						}
					}
				}
				else {
					if (unitPosition.x < display1.getMapSize().x - 12) {
						unitPosition.x++;
					}
					else {
						if (unitPosition.y < (display1.getMapSize().y) / 2) {
							unitPosition.y++;
						}
						else {
							unitPosition.y--;
						}
					}
				}
				if (unitPtr->getWalkCycle() == 0) { unitPtr->setWalkCycle(1); }
				else { unitPtr->setWalkCycle(0); }
				unitPtr->setMapLocation(unitPosition);
				unitPtr->setLastMoveTime(steady_clock::now());
			}
		}
		drawUnit(unitPtr);
	}
}

void Game::towerAction(Tower* towerPtr) {
	if (towerPtr->getTowerType() == "Fortified Position") {
		display1.addMapGraphic(towerPtr->getMapLocation().x - towerPtr->getTowerWidth(), towerPtr->getMapLocation().y - towerPtr->getTowerHeight(), "fortifiedPosition.txt", 6);
	}
	if (towerPtr->getTowerType() == "Fort") {
		display1.addMapGraphic(towerPtr->getMapLocation().x - towerPtr->getTowerWidth(), towerPtr->getMapLocation().y - towerPtr->getTowerHeight(), "fort.txt", 6);
	}
	if (towerPtr->getTowerType() == "Tower") {
		display1.addMapGraphic(towerPtr->getMapLocation().x - towerPtr->getTowerWidth(), towerPtr->getMapLocation().y - towerPtr->getTowerHeight(), "tower.txt", 7);
	}
	if (towerPtr->getTowerType() == "Castle") {
		display1.addMapGraphic(towerPtr->getMapLocation().x - towerPtr->getTowerWidth(), towerPtr->getMapLocation().y - towerPtr->getTowerHeight(), "castle.txt", 8);
	}
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
}

void Game::moveViewer() {
	Coordinates viewerCoords = display1.getViewerCoords();
	Coordinates cursorCoords = cursor1.getMapLocation();

	if (isKeyPressed('W') || isKeyPressed('w')) {
		if (display1.getViewerCoords().y > 0) {
			viewerCoords.y--;
			cursorCoords.y--;
		}
	}
	if (isKeyPressed('S') || isKeyPressed('s')) {
		if (display1.getViewerCoords().y < (display1.getMapSize().y - 40)) {
			viewerCoords.y++;
			cursorCoords.y++;
		}
	}
	if (isKeyPressed('A') || isKeyPressed('a')) {
		if (display1.getViewerCoords().x > 0) {
			viewerCoords.x--;
			cursorCoords.x--;
		}
	}
	if (isKeyPressed('D') || isKeyPressed('d')) {
		if (display1.getViewerCoords().x < (display1.getMapSize().x - 150)) {
			viewerCoords.x++;
			cursorCoords.x++;
		}
	}

	display1.setViewer(viewerCoords);
	cursor1.setMapLocation(cursorCoords);
}

void Game::cursorAction() {

	Coordinates cursorScreenLocation = cursor1.getScreenLocation();
	Coordinates cursorMapLocation = cursor1.getMapLocation();

	if (steady_clock::now() - lastCursorXMoveTime >= milliseconds(30)) {

		if (isKeyPressed(VK_RIGHT)) {
			if (cursor1.getScreenLocation().x < 144) {
				cursorScreenLocation.x++;
				cursorMapLocation.x++;
				lastCursorXMoveTime = steady_clock::now();
			}
		}
		if (isKeyPressed(VK_LEFT)) {
			if (cursor1.getScreenLocation().x > 1) {
				cursorScreenLocation.x--;
				cursorMapLocation.x--;
				lastCursorXMoveTime = steady_clock::now();
			}
		}
	}

	if (steady_clock::now() - lastCursorYMoveTime >= milliseconds(60)) {

		if (isKeyPressed(VK_UP)) {
			if (cursor1.getScreenLocation().y > 10) {
				cursorScreenLocation.y--;
				cursorMapLocation.y--;
				lastCursorYMoveTime = steady_clock::now();
			}
		}
		if (isKeyPressed(VK_DOWN)) {
			if (cursor1.getScreenLocation().y < 46) {
				cursorScreenLocation.y++;
				cursorMapLocation.y++;
				lastCursorYMoveTime = steady_clock::now();
			}
		}
	}

	cursor1.setScreenLocation(cursorScreenLocation);
	cursor1.setMapLocation(cursorMapLocation);
	display1.addMapGraphic((cursorMapLocation.x - 2), (cursorMapLocation.y - 1), "cursor.txt", 12);
}

void Game::enemySpawn() {
	if (steady_clock::now() - lastEnemySpawnTime >= enemySpawnSpeed) {
		random_device seed;
		mt19937 gen(seed());
		uniform_int_distribution<int> probRange(2, 100);
		uniform_int_distribution<int> coordRange(0, display1.getMapSize().y - 1);

		int prob = probRange(gen);

		if (difficulty == "Easy") {
			if (prob <= 25) { objectVector.push_back(new Unit("Sword Guy!", {display1.getMapSize().x - 3, coordRange(gen)})); }
			if (prob >= 26 && prob <= 50) { objectVector.push_back(new Unit("Shield Man", { display1.getMapSize().x - 3, coordRange(gen) })); }
			if (prob >= 51 && prob <= 75) { objectVector.push_back(new Unit("Archer", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 76 && prob <= 85) { objectVector.push_back(new Unit("Brute", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 86 && prob <= 90) { objectVector.push_back(new Unit("Catapult", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 91 && prob <= 100) { objectVector.push_back(new Unit("Engineer", { display1.getMapSize().x - 2, coordRange(gen) })); }
		}
		if (difficulty == "Medium") {
			if (prob <= 10) { objectVector.push_back(new Unit("Sword Guy!", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 11 && prob <= 35) { objectVector.push_back(new Unit("Shield Man", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 36 && prob <= 60) { objectVector.push_back(new Unit("Archer", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 61 && prob <= 75) { objectVector.push_back(new Unit("Brute", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 76 && prob <= 85) { objectVector.push_back(new Unit("Catapult", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 86 && prob <= 100) { objectVector.push_back(new Unit("Engineer", { display1.getMapSize().x - 2, coordRange(gen) })); }
		}
		if (difficulty == "Hard") {
			if (prob <= 5) { objectVector.push_back(new Unit("Sword Guy!", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 6 && prob <= 25) { objectVector.push_back(new Unit("Shield Man", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 26 && prob <= 55) { objectVector.push_back(new Unit("Archer", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 56 && prob <= 70) { objectVector.push_back(new Unit("Brute", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 71 && prob <= 85) { objectVector.push_back(new Unit("Catapult", { display1.getMapSize().x - 2, coordRange(gen) })); }
			if (prob >= 86 && prob <= 100) { objectVector.push_back(new Unit("Engineer", { display1.getMapSize().x - 2, coordRange(gen) })); }
		}
		objectVector.at(objectVector.size() - 1)->setEnemy(true);
		lastEnemySpawnTime = steady_clock::now();
	}
}

void Game::drawUnit(Unit* unitPtr) {
	if (unitPtr->getUnitType() == "Sword Guy!") {
		if (unitPtr->getEnemy()) {
			display1.addMapGraphic(unitPtr->getMapLocation().x - 1, unitPtr->getMapLocation().y, unitPtr->getUnitType() + to_string(unitPtr->getWalkCycle()) + ".txt", 12);
		}
		else {
			display1.addMapGraphic(unitPtr->getMapLocation().x - 1, unitPtr->getMapLocation().y, unitPtr->getUnitType() + to_string(unitPtr->getWalkCycle()) + ".txt", 9);
		}
	}
	else if (unitPtr->getUnitType() == "Shield Man") {
		if (unitPtr->getEnemy()) {
			display1.addMapGraphic(unitPtr->getMapLocation().x - 1, unitPtr->getMapLocation().y - 1, unitPtr->getUnitType() + to_string(unitPtr->getWalkCycle()) + ".txt", 12);
		}
		else {
			display1.addMapGraphic(unitPtr->getMapLocation().x - 1, unitPtr->getMapLocation().y - 1, unitPtr->getUnitType() + to_string(unitPtr->getWalkCycle()) + ".txt", 9);
		}
	}
	else if (unitPtr->getUnitType() == "Brute") {
		if (unitPtr->getEnemy()) {
			display1.addMapGraphic(unitPtr->getMapLocation().x, unitPtr->getMapLocation().y - 1, unitPtr->getUnitType() + to_string(unitPtr->getWalkCycle()) + ".txt", 12);
		}
		else {
			display1.addMapGraphic(unitPtr->getMapLocation().x, unitPtr->getMapLocation().y - 1, unitPtr->getUnitType() + to_string(unitPtr->getWalkCycle()) + ".txt", 9);
		}
	}
	else {
		display1.addMapString(unitPtr->getMapLocation().x, unitPtr->getMapLocation().y, "R", 12);
	}
}

void Game::spawnUnit(string unitType) {
	if (unitType == "Sword Guy!") {
		if (money >= 1) {
			objectVector.push_back(new Unit(unitType, { 2,cursor1.getMapLocation().y }));
			objectVector.at(objectVector.size() - 1)->setEnemy(false);
			money--;
		}
	}
	if (unitType == "Shield Man") {
		if (money >= 3) {
			objectVector.push_back(new Unit(unitType, { 2,cursor1.getMapLocation().y }));
			objectVector.at(objectVector.size() - 1)->setEnemy(false);
			money = money - 3;
		}
	}
	if (unitType == "Archer") {
		if (money >= 2) {
			objectVector.push_back(new Unit(unitType, { 2,cursor1.getMapLocation().y }));
			objectVector.at(objectVector.size() - 1)->setEnemy(false);
			money = money - 2;
		}
	}
	if (unitType == "Brute") {
		if (money >= 4) {
			objectVector.push_back(new Unit(unitType, { 2,cursor1.getMapLocation().y }));
			objectVector.at(objectVector.size() - 1)->setEnemy(false);
			money = money - 4;
		}
	}
	if (unitType == "Catapult") {
		if (money >= 5) {
			objectVector.push_back(new Unit(unitType, { 2,cursor1.getMapLocation().y }));
			objectVector.at(objectVector.size() - 1)->setEnemy(false);
			money = money - 5;
		}
	}
	if (unitType == "Engineer") {
		if (money >= 4) {
			objectVector.push_back(new Unit(unitType, { 2,cursor1.getMapLocation().y }));
			objectVector.at(objectVector.size() - 1)->setEnemy(false);
			money = money - 4;
		}
	}
}
