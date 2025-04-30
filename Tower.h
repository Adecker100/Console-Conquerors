#pragma once

#include "Object.h"
#include "Unit.h"
#include <vector>

class Tower : public Object {
public:
	Tower();
	Tower(string, Coordinates);
	int getMaxUnits();
	int getNumUnits();
	float getHealthIncrease();
	float getRangeIncrease();
	string getTowerType();
	int getTowerWidth();
	int getTowerHeight();
	void setMaxUnits(int);
	void setNumUnits(int);
	void setHealthIncrease(float);
	void setRangeIncrease(float);
	void setTowerType(string);
	void setTowerWidth(int);
	void setTowerHeight(int);
	void addUnit(Unit*);
	Unit* getUnit(int);
	float getMaxHealth();
	vector<Unit*> getUnitVector();
private:
	float maxHealth;
	int maxUnits;
	int numUnits;
	float healthIncrease;
	float rangeIncrease;
	string towerType;
	int towerWidth;
	int towerHeight;
	vector<Unit*> unitVector;
};

