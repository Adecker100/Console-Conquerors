#include "Game.h"
#include <conio.h>
#include <random>


void Game::startGame() {
	display1.drawScreen();
	display1.clearScreen();
	display1.addString(0, 0, "Please enlarge the console window, then press any key to continue", 15);
	display1.drawScreen();
	waitForInput();
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
	display1.addString(51, 35, "Console Conquerors! written by Alex Decker 2025", 15);
	display1.addString(111, 45, "Press any key to continue...", 15);
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
	random_device seed;
	mt19937 gen(seed());
	uniform_int_distribution<int> probRange(1, 10);

	if (difficulty == "Easy") {
		uniform_int_distribution<int> xRange(1, 299);
		uniform_int_distribution<int> yRange(1, 99);
		display1.setMapSize(300, 100);
	}
	if (difficulty == "Medium") {
		uniform_int_distribution<int> xRange(1, 599);
		uniform_int_distribution<int> yRange(1, 299);
		display1.setMapSize(600, 300);
	}
	if (difficulty == "Hard") {
		uniform_int_distribution<int> xRange(1, 899);
		uniform_int_distribution<int> yRange(1, 899);
		display1.setMapSize(900, 900);
	}
}

void Game::renderOverlay() {

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

void Game::unitAction(Unit*) {

}

void Game::towerAction(Tower*) {

}

void Game::vectorLoop() {

}

void Game::moveViewer() {

}

void Game::moveCursor() {

}

void Game::enemySpawn() {

}
