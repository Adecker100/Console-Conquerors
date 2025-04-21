#include "Unit.h"

using namespace std;

Unit::Unit() {
	setObjectType("Unit");
	unitType = "Uninitialized Unit";
	health = 0.0;
	moveSpeed = 0.0;
	attackSpeed = 0.0;
	attackRange = 0;
	attackDamage = 0;
	unitCost = 0;
	attackType = "None";
	lastAttackTime = steady_clock::now() - seconds(5);
	lastMoveTime = steady_clock::now() - seconds(5);
}

Unit::Unit(string inputUnitType, Coordinates inputMapLocation) {
	setObjectType("Unit");
	unitType = inputUnitType;
	setMapLocation(inputMapLocation);
	lastAttackTime = steady_clock::now() - seconds(5);
	lastMoveTime = steady_clock::now() - seconds(5);

	if (unitType == "Sword Guy!") {
		health = 100.0;
		moveSpeed = 1.0;
		attackSpeed = 1.5;
		attackRange = 2;
		attackDamage = 25;
		unitCost = 1;
		attackType = "Precise";
	}

	if (unitType == "Archer") {
		health = 50.0;
		moveSpeed = 0.50;
		attackSpeed = 3.0;
		attackRange = 30;
		attackDamage = 10;
		unitCost = 2;
		attackType = "Precise";
	}

	if (unitType == "Shield Man") {
		health = 150.0;
		moveSpeed = 1.25;
		attackSpeed = 2.0;
		attackRange = 2;
		attackDamage = 25;
		unitCost = 3;
		attackType = "Precise";
	}

	if (unitType == "Brute") {
		health = 200.0;
		moveSpeed = 1.75;
		attackSpeed = 3.0;
		attackRange = 4;
		attackDamage = 35;
		unitCost = 4;
		attackType = "Area";
	}

	if (unitType == "Catapult") {
		health = 250.0;
		moveSpeed = 2.25;
		attackSpeed = 5.0;
		attackRange = 20;
		attackDamage = 50;
		unitCost = 5;
		attackType = "Area";
	}

	if (unitType == "Engineer") {
		health = 50.0;
		moveSpeed = 1.0;
		attackSpeed = 3.5;
		attackRange = 1;
		attackDamage = 25;
		unitCost = 4;
		attackType = "Precise";
	}
}

float Unit::getHealth() {
	return health;
}

string Unit::getUnitType() {
	return unitType;
}

string Unit::getAttackType() {
	return attackType;
}

int Unit::getUnitCost() {
	return unitCost;
}

int Unit::getAttackDamage() {
	return attackDamage;
}

float Unit::getAttackRange() {
	return attackRange;
}

float Unit::getAttackSpeed() {
	return attackSpeed;
}

float Unit::getMoveSpeed() {
	return moveSpeed;
}

time_point<steady_clock> Unit::getLastMoveTime() {
	return lastMoveTime;
}

time_point<steady_clock> Unit::getLastAttackTime() {
	return lastAttackTime;
}

void Unit::setHealth(float newHealth) {
	health = newHealth;
}

void Unit::setMoveSpeed(float newMoveSpeed) {
	moveSpeed = newMoveSpeed;
}

void Unit::setAttackSpeed(float newAttackSpeed) {
	attackSpeed = newAttackSpeed;
}

void Unit::setAttackRange(float newAttackRange) {
	attackRange = newAttackRange;
}

void Unit::setAttackDamage(int newAttackDamage) {
	attackDamage = newAttackDamage;
}

void Unit::setUnitCost(int newUnitCost) {
	unitCost = newUnitCost;
}

void Unit::setAttackType(string newAttackType) {
	attackType = newAttackType;
}

void Unit::setLastAttackTime(time_point<steady_clock> newTime) {
	lastAttackTime = newTime;
}

void Unit::setLastMoveTime(time_point<steady_clock> newTime) {
	lastMoveTime = newTime;
}

void Unit::setUnitType(string newUnitType) {
	unitType = newUnitType;
}