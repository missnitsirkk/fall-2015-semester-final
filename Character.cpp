
//Intro to C++

#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>  

#include "Character.h"

	//a new character is born

	Character::Character()
		: name(""), currentHealth(0), maxHealth(0), defense(0), maxAttack(0)
	{
	}

	Character::Character(std::string user) {
		setName(user);
		setCurHealth(10000);
		setMaxHealth(12000);
		setDefense(50);
		setMaxAttack(100);
	}

	Character::Character(std::string n, int c, int h, double d, int a) {
		setName(n);
		setCurHealth(c);
		setMaxHealth(h);
		setDefense(d);
		setMaxAttack(a);
	}

	//we got the names

	void Character::setName(std::string user) 
	{
		name = user;
	}
	std::string Character::getName() const
	{
		return name;
	}

	// we got the current health

	void Character::setCurHealth(int H) {
		currentHealth = H;
	}
	int Character::getCurHealth() const {
		return currentHealth;
	}

	// we got the max health

	void Character::setMaxHealth(int MH) {
		maxHealth = MH;
	}
	int Character::getMaxHealth() const {
		return maxHealth;
	}

	//we got the defense 

	void Character::setDefense(double D) {
		defense = D;
	}
	double Character::getDefense() const {
		return defense;
	}

	//we got the attacks

	void Character::setMaxAttack(int MA) {
		maxAttack = MA;
	}
	int Character::getMaxAttack() const {
		return maxAttack;
	}

	// determining our condition

	Character::State Character::getState()
	{
		if (currentHealth <= 0)
			return Character::State::DEAD;
		else if (currentHealth <= (maxHealth/2))
			return Character::State::BLOODY;
		else {
			return Character::State::NORMAL;
		}
	}


	std::string Character::getStateText() {
		switch (getState()) {
		case State::DEAD: return "Dead.";
		case State::BLOODY: return "Wounded.";
		case State::NORMAL: return "Alive.";
		}
	}

	//checking our current condition

	void Character::displayCharStats() {
		std::cout << "Name: " << getName() << std::endl;
		std::cout << "Current Health: " << getCurHealth() << std::endl;
		std::cout << "Status: " << getStateText() << "\n" << std::endl;
	}

	//attack

	int Character::attack()
	{
		int hit  = (getMaxAttack() * (74 + rand() % 25));
		return hit;
	}

	//be attacked

	int Character::takeDamage(int d)
	{
		int damage = (d - (d/2)); //damage modified
		setCurHealth(currentHealth - damage);
		return damage;
	}

	void Character::heal() {
		setCurHealth(currentHealth + (50 + rand() % 5));
	}

	void Character::fullHeal() {
		setCurHealth(maxHealth);
	}

	



