// Console Conquerors! written by Alex Decker 2025

#include "Game.h"
#include "DisplayV2.h"
#include <iostream>

using namespace std;

int main()
{
	try {
		Game game1;
		game1.titleScreen();
	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
	}
	return 0;
}
