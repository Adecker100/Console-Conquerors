#include "Tower.h"

using namespace std;

Tower::Tower() {
	setObjectType("Tower");
	numUnits = 0;
}

Tower::Tower(string inputTowerType) {

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

void Tower::releaseUnits() {

}

Unit* Tower::getUnit(int index) {
	if (index < 1 || index > unitVector.size()) {
		throw runtime_error("Tower::getUnit(int index) 'index' out of range of unitVector. index: " + index);
	}
	return unitVector.at(index);
}