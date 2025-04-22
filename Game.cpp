#include "Game.h"
#include "DisplayV2.h"
#include "Unit.h"
#include "Tower.h"
#include <conio.h>

void Game::titleScreen() {
	display1.drawScreen();
	display1.clearScreen();
	for (int i = 0; i < 11; i++) {
		display1.addGraphic(18, i, "Title.txt", 10);
		display1.drawScreen();
		display1.clearScreenBuffer();
	}
	display1.addGraphic(18, 10, "Title.txt", 10);
	display1.addString(50, 40, "Console Conquerors! written by Alex Decker 2025", 15);
	display1.drawScreen();
}

void Game::diffSelect() {

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

}

void Game::infoOverlay() {

}

void Game::winGame() {

}

void Game::loseGame() {

}

void Game::unitBar() {

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
