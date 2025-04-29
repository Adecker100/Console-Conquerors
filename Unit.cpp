#include "Unit.h"

using namespace std;

Unit::Unit() {
	setObjectType("Unit");
	unitType = "Uninitialized Unit";
	setHealth(0.0);
	moveSpeed = duration<double>(0.0);
	attackSpeed = duration<double>(0.0);
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
	if (inputMapLocation.y >= 0) {
		setMapLocation(inputMapLocation);
	}
	lastAttackTime = steady_clock::now() - seconds(5);
	lastMoveTime = steady_clock::now() - seconds(5);

	if (unitType == "Sword Guy!") {
		setHealth(100.0);
		moveSpeed = duration<double>(1.0);
		attackSpeed = duration<double>(1.5);
		attackRange = 2;
		attackDamage = 25;
		unitCost = 1;
		attackType = "Precise";
	}

	if (unitType == "Archer") {
		setHealth(50.0);
		moveSpeed = duration<double>(0.50);
		attackSpeed = duration<double>(3.0);
		attackRange = 30;
		attackDamage = 10;
		unitCost = 2;
		attackType = "Precise";
	}

	if (unitType == "Shield Man") {
		setHealth(150.0);
		moveSpeed = duration<double>(1.25);
		attackSpeed = duration<double>(2.0);
		attackRange = 2;
		attackDamage = 25;
		unitCost = 3;
		attackType = "Precise";
	}

	if (unitType == "Brute") {
		setHealth(200.0);
		moveSpeed = duration<double>(1.75);
		attackSpeed = duration<double>(3.0);
		attackRange = 4;
		attackDamage = 35;
		unitCost = 4;
		attackType = "Area";
	}

	if (unitType == "Catapult") {
		setHealth(250.0);
		moveSpeed = duration<double>(2.25);
		attackSpeed = duration<double>(5.0);
		attackRange = 20;
		attackDamage = 50;
		unitCost = 5;
		attackType = "Area";
	}

	if (unitType == "Engineer") {
		setHealth(50.0);
		moveSpeed = duration<double>(1.0);
		attackSpeed = duration<double>(3.5);
		attackRange = 2;
		attackDamage = 25;
		unitCost = 4;
		attackType = "Precise";
	}
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

int Unit::getDeadColor() {
	return deadColor;
}

bool Unit::getAlive() {
	return alive;
}

float Unit::getAttackRange() {
	return attackRange;
}

duration<double> Unit::getAttackSpeed() {
	return attackSpeed;
}

duration<double> Unit::getMoveSpeed() {
	return moveSpeed;
}

time_point<steady_clock> Unit::getLastMoveTime() {
	return lastMoveTime;
}

time_point<steady_clock> Unit::getLastAttackTime() {
	return lastAttackTime;
}

void Unit::setAlive(bool newAlive) {
	alive = newAlive;
}

void Unit::setMoveSpeed(duration<double> newMoveSpeed) {
	moveSpeed = newMoveSpeed;
}

void Unit::setAttackSpeed(duration<double> newAttackSpeed) {
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

void Unit::setDeadColor(int newDeadColor) {
	deadColor = newDeadColor;
}

int Unit::getWalkCycle() {
	return walkCycle;
}

void Unit::setWalkCycle(int newWalkCycle) {
	walkCycle = newWalkCycle;
}

int Unit::getAttacking() {
	return attacking;
}

void Unit::setAttacking(int newAttacking) {
	attacking = newAttacking;
}