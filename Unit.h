#pragma once

#include "Object.h"
#include <string>
#include <chrono>

using namespace std::chrono;

class Unit : public Object {
public:
	Unit();
	Unit(string, Coordinates);
	float getHealth();
	string getUnitType();
	string getAttackType();
	int getUnitCost();
	int getAttackDamage();
	float getAttackRange();
	float getAttackSpeed();
	float getMoveSpeed();
	time_point<steady_clock> getLastMoveTime();
	time_point<steady_clock> getLastAttackTime();
	void setHealth(float);
	void setMoveSpeed(float);
	void setAttackSpeed(float);
	void setAttackRange(float);
	void setAttackDamage(int);
	void setUnitCost(int);
	void setAttackType(string);
	void setLastAttackTime(time_point<steady_clock>);
	void setLastMoveTime(time_point<steady_clock>);
	void setUnitType(string);
private:
	float health;
	float moveSpeed;
	float attackSpeed;
	float attackRange;
	int attackDamage;
	int unitCost;
	string attackType;
	string unitType;
	time_point<steady_clock> lastAttackTime;
	time_point<steady_clock> lastMoveTime;
};

