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
		maxHealth = 500.0;
		healthIncrease = 1.1;
		rangeIncrease = 1.1;
		towerWidth = 2;
		towerHeight = 1;
	}

	if (towerType == "Fort") {
		maxUnits = 20;
		setHealth(750.0);
		maxHealth = 750.0;
		healthIncrease = 1.25;
		rangeIncrease = 1.2;
		towerWidth = 3;
		towerHeight = 2;
	}

	if (towerType == "Tower") {
		maxUnits = 20;
		setHealth(1000.0);
		maxHealth = 1000.0;
		healthIncrease = 1.5;
		rangeIncrease = 1.75;
		towerWidth = 5;
		towerHeight = 2;
	}

	if (towerType == "Castle") {
		maxUnits = 30;
		setHealth(2000.0);
		maxHealth = 2000.0;
		healthIncrease = 2.0;
		rangeIncrease = 1.5;
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
		newUnit->setMapLocation(getMapLocation());
		numUnits++;
	}
}

Unit* Tower::getUnit(int index) {
	if (index < 0 || index > unitVector.size()) {
		throw runtime_error("Tower::getUnit(int index) 'index' out of range of unitVector. index: " + index);
	}
	return unitVector.at(index);
}

float Tower::getMaxHealth() {
	return maxHealth;
}

vector<Unit*> Tower::getUnitVector() {
	return unitVector;
}