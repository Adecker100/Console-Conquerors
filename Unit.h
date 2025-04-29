#pragma once

#include "Object.h"
#include <string>
#include <chrono>

using namespace std::chrono;

class Unit : public Object {
public:
	Unit();
	Unit(string, Coordinates);
	string getUnitType();
	string getAttackType();
	int getUnitCost();
	int getAttackDamage();
	int getDeadColor();
	bool getAlive();
	float getAttackRange();
	duration<double> getAttackSpeed();
	duration<double> getMoveSpeed();
	time_point<steady_clock> getLastMoveTime();
	time_point<steady_clock> getLastAttackTime();
	void setAlive(bool);
	void setMoveSpeed(duration<double>);
	void setAttackSpeed(duration<double>);
	void setAttackRange(float);
	void setAttackDamage(int);
	void setUnitCost(int);
	void setAttackType(string);
	void setLastAttackTime(time_point<steady_clock>);
	void setLastMoveTime(time_point<steady_clock>);
	void setUnitType(string);
	void setDeadColor(int);
	int getWalkCycle();
	void setWalkCycle(int);
	int getAttacking();
	void setAttacking(int);
private:
	int walkCycle = 0;
	int attacking = 0;
	int deadColor = 0;
	bool alive = true;
	duration<double> moveSpeed;
	duration<double> attackSpeed;
	float attackRange;
	int attackDamage;
	int unitCost;
	string attackType;
	string unitType;
	time_point<steady_clock> lastAttackTime;
	time_point<steady_clock> lastMoveTime;
};

