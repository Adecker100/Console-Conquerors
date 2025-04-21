#include "Tower.h"

using namespace std;

Tower::Tower() {
	setObjectType("Tower");
	towerType = "Uninitialized Tower";
	numUnits = 0;
	maxUnits = 0;
	health = 100.0;
	healthIncrease = 0.0;
	rangeIncrease = 0.0;
	towerSize = 0;
}

Tower::Tower(string inputTowerType, Coordinates inputMapLocation) {
	setObjectType("Tower");
	setMapLocation(inputMapLocation);
	towerType = inputTowerType;
	numUnits = 0;

	if (towerType == "Fortified Position") {
		maxUnits = 10;
		health = 500.0;
		healthIncrease = 10.0;
		rangeIncrease = 10.0;
		towerSize = 0;
	}

	if (towerType == "Fort") {
		maxUnits = 20;
		health = 750.0;
		healthIncrease = 25.0;
		rangeIncrease = 20.0;
		towerSize = 0;
	}

	if (towerType == "Tower") {
		maxUnits = 20;
		health = 1000.0;
		healthIncrease = 50.0;
		rangeIncrease = 75.0;
		towerSize = 0;
	}

	if (towerType == "Castle") {
		maxUnits = 30;
		health = 2000.0;
		healthIncrease = 100.0;
		rangeIncrease = 50.0;
		towerSize = 0;
	}
}

float Tower::getHealth() {
	return health;
}

int Tower::getMaxUnits() {
	return maxUnits;
}

int Tower::getNumnUnits() {
	return numUnits;
}

float Tower::getHealthIncrease() {
	return healthIncrease;
}

float Tower::getRangeIncrease() {
	return rangeIncrease;
}

string Tower::getTowerType() {
	return towerType;
}

int Tower::getTowerSize() {
	return towerSize;
}

void Tower::setHealth(float newHealth) {
	health = newHealth;
}

void Tower::setMaxUnits(int newMaxUnits) {
	maxUnits = newMaxUnits;
}

void Tower::setNumUnits(int newNumUnits) {
	numUnits = newNumUnits;
}

void Tower::setHealthIncrease(float newHealthIncrease) {
	healthIncrease = newHealthIncrease;
}

void Tower::setRangeIncrease(float newRangeIncrease) {
	rangeIncrease = newRangeIncrease;
}

void Tower::setTowerType(string newTowerType) {
	towerType = newTowerType;
}

void Tower::setTowerSize(int newTowerSize) {
	towerSize = newTowerSize;
}

void Tower::addUnit(Unit* newUnit) {
	if (numUnits < maxUnits) {
		unitVector.push_back(newUnit);
		numUnits++;
	}
}

Unit* Tower::getUnit(int index) {
	if (index < 1 || index > unitVector.size()) {
		throw runtime_error("Tower::getUnit(int index) 'index' out of range of unitVector. index: " + index);
	}
	return unitVector.at(index);
}