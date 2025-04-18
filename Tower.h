#pragma once

#include "Object.h"
#include "Unit.h"
#include <vector>

class Tower : public Object {
public:
	Tower();
	Tower(string);
	float getHealth();
	int getMaxUnits();
	int getNumnUnits();
	float getHealthIncrease();
	float getRangeIncrease();
	string getTowerType();
	int getTowerSize();
	void setHealth(float);
	void setMaxUnits(int);
	void setNumUnits(int);
	void setHealthIncrease(float);
	void setRangeIncrease(float);
	void setTowerType(string);
	void setTowerSize(int);
	void addUnit(Unit*);
	void releaseUnits();
	Unit* getUnit(int);
private:
	float health;
	int maxUnits;
	int numUnits;
	float healthIncrease;
	float rangeIncrease;
	string towerType;
	int towerSize;
	vector<Unit*> unitVector;
};

