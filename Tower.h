#pragma once

#include "Object.h"
#include "Unit.h"
#include <vector>

class Tower : public Object {
public:
	Tower();
	Tower(string, Coordinates);
	float getHealth();
	int getMaxUnits();
	int getNumnUnits();
	float getHealthIncrease();
	float getRangeIncrease();
	string getTowerType();
	int getTowerWidth();
	int getTowerHeight();
	void setHealth(float);
	void setMaxUnits(int);
	void setNumUnits(int);
	void setHealthIncrease(float);
	void setRangeIncrease(float);
	void setTowerType(string);
	void setTowerWidth(int);
	void setTowerHeight(int);
	void addUnit(Unit*);
	Unit* getUnit(int);
private:
	float health;
	int maxUnits;
	int numUnits;
	float healthIncrease;
	float rangeIncrease;
	string towerType;
	int towerWidth;
	int towerHeight;
	vector<Unit*> unitVector;
};

