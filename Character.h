//Intro to C++

#pragma once
#include <iostream>
#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {

public: 
	//default constructor
	Character();
	//constructor building from a new user
	explicit Character(std::string);
	//constructor when all parameters are provided 
	Character(std::string, int, int, double, int);

	//basic data
	void setName(std::string);
	std::string getName() const;
	void setCurHealth(int);
	int getCurHealth() const;
	void setMaxHealth(int);
	int getMaxHealth() const;
	void setDefense(double);
	double getDefense() const;
	void setMaxAttack(int);
	int getMaxAttack() const;

	//determining our condition
	enum State { DEAD, BLOODY, NORMAL };
	State getState();
	std::string getStateText();

	//checking our current condition
	void displayCharStats();

	//fighting functions
	int attack();
	int takeDamage(int d);
	void heal();
	void fullHeal();


private: 
	std::string name;
	int currentHealth;
	int maxHealth;
	double defense;
	int maxAttack;

};

#endif
