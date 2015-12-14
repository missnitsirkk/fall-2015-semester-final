#include <iostream>
#include <ostream>
#include <iomanip>
#include "MapTile.h"
#include "Character.h"

MapTile::MapTile() {
	setDescription("blank");
	enemyPtr = nullptr;
	arraySz = 0;
}

MapTile::MapTile(std::string d) {
	setDescription(d);
	arraySz = 0;
}

MapTile::MapTile(std::string d, Character c[], int aSz) {
	setDescription(d);
	arraySz = aSz;
	enemyPtr = c;
}

void MapTile::setDescription(std::string d)
{
	description = d;
}

std::string MapTile::getDescription()
{
	return description;
}


bool MapTile::hasEnemiesLeft() {
	if (enemyPtr == 0) {
		return false;
	}
	else {
		return true;
	}
}


int MapTile::setArraySize(int sz) {
	arraySz = sz;
}

int MapTile::getArraySize() {
	return arraySz;
}


std::ostream &operator<<(std::ostream &output, MapTile &location) {

	output << "You are in " << location.getDescription << " with "
		<< location.getArraySize << " enemies to fight." << std::endl;

}
