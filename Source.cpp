
//Intro to C++

#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
#include "Character.h"

using namespace std;


int main() {

	int repeat = 0;

	while (repeat == 0) {

		string user = "";
		cout << "Welcome...\n\nWho's playing tonight? Name: ";
		cin >> user;

		//create our fighter
		Character player(user);
		//instantiate the console
		Character console("Mack the Knife", 10000, 10000, 30, 40);

		cout << "\nReady to tango, " << player.getName() << "? Let's begin.\n" << endl;
		player.displayCharStats();

		cout << "\nSo is your opponent: \n" << endl;
		console.displayCharStats();

		cout << "\nPress 3 to attack, 2 to rest, 1 to quit... \n" << endl;
		srand(time(0));

		int command;
		cin >> command;

		while (command != 1) {
			if (command == 3) {
				cout << "Bam! Nice Hit, Reduced Mack: " << console.takeDamage(player.attack()) << " Points" << endl;
			}
			else if (command == 2) {
				if (player.getCurHealth() % 3 == 0) {
					player.fullHeal();
				}
				else {
					player.heal();
				}
				std::cout << "Take a Break to Heal... Your Current Health is Now: " << player.getCurHealth() << std::endl;
			}
			else {
				std::cout << "Invalid Command, You Missed Your Turn\n";
			}

			std::cout << "\nMack makes his move, watch out!\n\n--Swipe--\n\n" << std::endl;
			player.takeDamage(console.attack());

			player.displayCharStats();
			console.displayCharStats();

			if (console.getCurHealth() < 0) {
				std::cout << "Rest in peace, Mack. \n\n" << std::endl;
				command = 1;
				break;
			}
			if (player.getCurHealth() < 0) {
				std::cout << "You lost too much blood, game over for you.\n" << std::endl;
				command = 1;
				break;
			}
			else {
				std::cout << "\nPress '3' to attack, '2' to rest, '1' to quit... \n" << std::endl;
				std::cin >> command;
			}
			


		}
		cout << "Press zero to play again..."; 
		cin >> repeat;
	}

	system("pause");
}
