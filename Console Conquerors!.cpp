// Console Conquerors! written by Alex Decker 2025

#include "Game.h"
#include "DisplayV2.h"
#include <iostream>

using namespace std;

int main()
{
	try {
		DisplayV2 display1;
		display1.drawScreen();
			display1.clearScreen();
			display1.drawScreen();
			display1.addBorder('#', 13);
			display1.drawScreen();
			display1.addString(130, 40, "test.txt", 15);
			display1.drawScreen();
	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
	}
	return 0;
}
