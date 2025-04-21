#include "Unit.h"

using namespace std;

Unit::Unit() {

}

Unit::Unit(string inputUnitType) {

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

}

void Unit::setMoveSpeed(float newMoveSpeed) {

}

void Unit::setAttackSpeed(float newAttackSpeed) {

}

void Unit::setAttackRange(float newAttackRange) {

}

void Unit::setAttackDamage(float newAttackDamage) {

}

void Unit::setUnitCost(int newUnitCost) {

}

void Unit::setAttackType(string newAttackType) {

}

void Unit::setLastAttackTime(time_point<steady_clock> newTime) {

}

void Unit::setLastMoveTime(time_point<steady_clock> newTime) {

}

void Unit::setUnitType(string newUnitType) {

}