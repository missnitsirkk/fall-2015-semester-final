#pragma once
#include <string>
#include "Character.h"

class MapTile {

public:
	MapTile();
	MapTile(std::string);
	MapTile(std::string, Character[], int);
	void setDescription(std::string);
	std::string getDescription();
	bool hasEnemiesLeft();
	int setArraySize(int);
	int getArraySize();

	void setDescription(std::string d);

	friend std::ostream &operator<<(std::ostream &, MapTile &);
private:
	std::string description;
	Character* enemyPtr;
	int arraySz;

}; 
