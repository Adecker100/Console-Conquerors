#include "Tower.h"

using namespace std;

Tower::Tower() {
	setObjectType("Tower");
	towerType = "Uninitialized Tower";
	numUnits = 0;
	maxUnits = 0;
	setHealth(100.0);
	healthIncrease = 0.0;
	rangeIncrease = 0.0;
	towerWidth = 0;
	towerHeight = 0;
}

Tower::Tower(string inputTowerType, Coordinates inputMapLocation) {
	setObjectType("Tower");
	setMapLocation(inputMapLocation);
	towerType = inputTowerType;
	numUnits = 0;

	if (towerType == "Fortified Position") {
		maxUnits = 10;
		setHealth(500.0);
		healthIncrease = 10.0;
		rangeIncrease = 10.0;
		towerWidth = 2;
		towerHeight = 1;
	}

	if (towerType == "Fort") {
		maxUnits = 20;
		setHealth(50.0);
		healthIncrease = 25.0;
		rangeIncrease = 20.0;
		towerWidth = 3;
		towerHeight = 2;
	}

	if (towerType == "Tower") {
		maxUnits = 20;
		setHealth(1000.0);
		healthIncrease = 50.0;
		rangeIncrease = 75.0;
		towerWidth = 5;
		towerHeight = 2;
	}

	if (towerType == "Castle") {
		maxUnits = 30;
		setHealth(2000.0);
		healthIncrease = 100.0;
		rangeIncrease = 50.0;
		towerWidth = 7;
		towerHeight = 4;
	}
}

int Tower::getMaxUnits() {
	return maxUnits;
}

int Tower::getNumUnits() {
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

int Tower::getTowerWidth() {
	return towerWidth;
}

int Tower::getTowerHeight() {
	return towerHeight;
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

void Tower::setTowerWidth(int newTowerWidth) {
	towerWidth = newTowerWidth;
}

void Tower::setTowerHeight(int newTowerHeight) {
	towerHeight = newTowerHeight;
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