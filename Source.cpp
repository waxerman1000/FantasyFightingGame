//Andrew Green
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <fstream>
#include "Character.h"
	#include "Player.h"
	#include "Grunt.h"
#include "Item.h"
#include "Shop.h"
#include "Arena.h"




using namespace std;

int main() {
	//INITIALIZE EVERYTHING
	Grunt grunt;
	Player player;
	Shop shop;
	Arena arena;

	srand(time(NULL));

	string userInput = "";
	int randInt = 0;
	char tempChar = 'o';
	bool gaming = true;
	bool isViewing = true;
	bool isViewingItem = false;
	bool firstMatch = true;
	int tempInt = 0;
	vector<string> items;
	string tempText;
	string text;

	//FIND SAVE FILE
	cout << "\n\n\n\n\n\t\tLoad save? (y/n)\n";
	cin >> userInput;
	if (userInput == "y") {
		//OPEN FILE
		fstream file;
		file.open("save.txt", ios::out | ios::in);
		
		while (file.is_open()) {
			//LOAD AND GIVE ITEMS
			while ((tempText.size() == 0) || (tempText[tempText.size() - 1] != '.')) {
				text = "";
				file >> tempText;
				if (tempText[tempText.size() - 1] != ',' && tempText[tempText.size() - 1] != '.') {
				text += tempText + " ";
				file >> tempText;
				}
				text += tempText;
				if ((text[text.size() - 1] == ',') || (text[text.size() - 1] == '.')) {
					text.erase(text.size() - 1);
				}
				items.push_back(text);
			}
			for (int i = 0; i < items.size(); i++) {
				if (items[i] != "LongSword") {
					player.giveItem(shop.giveItem(shop.findItem(items[i])));
				}
			}
			//EQUIP ITEM
			tempText = "";
			while ((tempText.size() == 0) || (tempText[tempText.size() - 1] != '.')) {
				text = "";
				file >> tempText;
					if (tempText[tempText.size() - 1] != ',' && tempText[tempText.size() - 1] != '.') {
					text += tempText + " ";
					file >> tempText;
				}
				text += tempText;
				if ((text[text.size() - 1] == ',') || (text[text.size() - 1] == '.')) {
					text.erase(text.size() - 1);
				}
			}
			if (text != "LongSword") {
				player.equipItem(player.pullItem(player.findItem(text)));
			}
			//GIVE ARMORS
			items.clear();
			tempText = "";
			while ((tempText.size() == 0) || (tempText[tempText.size() - 1] != '.')) {
				text = "";
				file >> tempText;
				if (tempText[tempText.size() - 1] != ',' && tempText[tempText.size() - 1] != '.') {
					text += tempText + " ";
					file >> tempText;
				}
				text += tempText;
				if ((text[text.size() - 1] == ',') || (text[text.size() - 1] == '.')) {
					text.erase(text.size() - 1);
				}
				items.push_back(text);
			}
			for (int i = 0; i < items.size(); i++) {
				if (items[i] != "Cloth Armor") {
					player.giveArmor(shop.giveArmor(shop.findArmor(items[i])));
				}
			}
			//EQUIP ARMORS
			tempText = "";
			while ((tempText.size() == 0) || (tempText[tempText.size() - 1] != '.')) {
				text = "";
				file >> tempText;
				if (tempText[tempText.size() - 1] != ',' && tempText[tempText.size() - 1] != '.') {
					text += tempText + " ";
					file >> tempText;
				}
				text += tempText;
				if ((text[text.size() - 1] == ',') || (text[text.size() - 1] == '.')) {
					text.erase(text.size() - 1);
				}
			}
			
			if (text != "Cloth Armor") {
				player.equipArmor(player.pullArmor(player.findArmor(text)));
			}
			//GIVE/TAKE POTS
			tempText = "";
			file >> tempText;
			tempInt = stoi(tempText);
			player.removePotion();
			for (int i = 0; i < tempInt; i++) {
				player.addPotion();
			}
			//GIVE/TAKE GOLD
			tempText = "";
			file >> tempText;
			tempInt = stoi(tempText);
			player.removeMoney(120);
			player.addMoney(tempInt);
			//EQUIP ITEM FOR GRUNT
			tempText = "";
			while ((tempText.size() == 0) || (tempText[tempText.size() - 1] != '.')) {
				text = "";
				file >> tempText;
				if (tempText[tempText.size() - 1] != ',' && tempText[tempText.size() - 1] != '.') {
					text += tempText + " ";
					file >> tempText;
				}
				text += tempText;
				if ((text[text.size() - 1] == ',') || (text[text.size() - 1] == '.')) {
					text.erase(text.size() - 1);
				}
			}
			if (text != "LongSword") {
				grunt.equipItem(grunt.pullItem(grunt.findItem(text)));
			}
			//EQUIP ARMOR FOR GRUNT
			tempText = "";
			while ((tempText.size() == 0) || (tempText[tempText.size() - 1] != '.')) {
				text = "";
				file >> tempText;
				if (tempText[tempText.size() - 1] != ',' && tempText[tempText.size() - 1] != '.') {
					text += tempText + " ";
					file >> tempText;
				}
				text += tempText;
				if ((text[text.size() - 1] == ',') || (text[text.size() - 1] == '.')) {
					text.erase(text.size() - 1);
				}
			}

			if (text != "Cloth Armor") {
				grunt.equipArmor(grunt.pullArmor(grunt.findArmor(text)));
			}
			file.close();
		}
		
		cout << "\nProgress loaded.\n\n";
	}
	else {
		//PRINT INTRODUCTION
		cout << "Hello! And welcome to the rift." << endl;
		cout << "Here, everything revolves around our arena, where people can compete for glory!!" << endl;
		cout << "You're just entering for the first time, so I'll give you a quick info drop." << endl;
			cout << "\t\tEnter anything to continue..." << endl;;
			cin >> userInput;
		cout << "\nBy entering 1 in the menu, you'll be able to view your inventory and item stats," << endl;
		cout << "\talong with the ability to equip the items for battle." << endl;
		cout << "\tBy default, you just have a longsword and some basic cloth wrappings for armor." << endl;
		cout << "\tYou can get more items in the shop, with each weapon having a unique passive ability." << endl;
			cout << "\t\tEnter anything to continue..." << endl;;
			cin >> userInput;
		cout << "By entering 2, you'll be able to view the shop, where you can see what's for sale" << endl;
		cout << "\tand what makes everything so special. You can also buy refillable health potions there, which" << endl;
		cout << "\tyou can use in battle to heal you a bit, and gain back after battle." << endl;
			cout << "\t\tEnter anything to continue..." << endl;;
			cin >> userInput;
		cout << "By entering 3, you can view your cumulative stats, and what you currently have equipped," << endl;
		cout << "and by entering 4, you can see your next opponents cumulative stats, and what THEY have." << endl;
		cout << "\tEach opponent you face will have different item combinations, except for the first" << endl;
		cout << "\ttwo, which will be toned down to help you get settled in here." << endl;
			cout << "\t\tEnter anything to continue..." << endl;;
			cin >> userInput;
		cout << "Finally, by entering 5, you enter the arena and face your next opponent in turn based combat." << endl;
		cout << "\tYou can attack to hurt your opponent, defend to reduce the incoming damage from your" << endl;
		cout << "\topponent's next attack, drink a health potion to restore some health, or forfeit." << endl;
		cout << "\tWhen you win, you gain 80 gold! If you lose, however, you lose 80 gold." << endl;
		cout << "\tForfeiting allows you to surrender to your enemy, and only lose 40 gold." << endl;
			cout << "\t\tEnter anything to continue..." << endl;;
			cin >> userInput;
		cout << "Well, that about does it. Good luck out there!" << endl;
		cout << "\t\tEnter anything to continue..." << endl;;
		cin >> userInput;
	}
	

	while (gaming){
		//MAIN MENU
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << setw(35);
		cout << "Welcome back to the rift!\n";
		cout << setw(0);
		cout << "1. View Inventory \t\t 4. View Next Match\n\n";
		cout << "2. Visit Shop \n\n";
		cout << "3. View your stats \t\t 5. Proceed to next battle ->\n\n";
		cout << "0. Quit\n\n";
		cout << "Where would you like to go? (type the number of your destination\nand hit enter)" << endl;;

		cin >> userInput;
		cout << "\n\n\n";

		if (userInput == "1") {
			//VIEW INVENTORY
			isViewing = true;
			while (isViewing) {
				cout << setw(35);
				cout << "Your Inventory:\n";
				cout << setw(0);
				player.printInventory();
				cout << "\nYou have " << player.getMoney() << " gold." << endl;
				cout << "\n\n\t\tEnter any letter to return,\n\t\tor a number to view the corresponding Item." << endl;
				cin >> userInput;
				isViewingItem = false;
				tempChar = userInput[0];
				if (isdigit(tempChar)) {
					isViewingItem = true;
				}
				else {
					isViewing = false;
				}
				if (isViewingItem) {
					//VIEW ITEM
					tempInt = stoi(userInput);
					player.getItem(tempInt);
					cout << "\n\n\t\tEnter any letter to return,\n\t\tor 5 to equip the Item." << endl;
					cin >> userInput;
					if (userInput == "5") {
						//EQUIP ITEM
						if (player.pullingItem(tempInt)) {
							player.equipItem(player.pullItem(tempInt));
						}
						else {
							player.equipArmor(player.pullItem(tempInt));
						}
					}
					else { isViewingItem = false; }
				}
				
			}
			
		}
		else if (userInput == "2") {
			//VISIT SHOP
			isViewing = true;
			while (isViewing) {
				cout << setw(35);
				cout << "The Shop\n";
				cout << setw(0);
				shop.displayItems();
				cout << "\n\n\t\tEnter any letter to return,\n\t\tor a number to view the corresponding Item." << endl;
				cin >> userInput;
				isViewingItem = false;
				tempChar = userInput[0];
				if (isdigit(tempChar)) {
					isViewingItem = true;
				}
				else {
					isViewing = false;
				}
				while (isViewingItem) {
					//VIEW ITEM
					tempInt = stoi(userInput);
					shop.displayItem(tempInt);
					cout << "Costs " << shop.itemPrice(tempInt) << " gold.";
					cout << "\n\n\t\tEnter any letter to return,\n\t\tor 5 to buy the Item." << endl;
					cin >> userInput;
					if (userInput == "5") {
						//BUY ITEM
						if ((tempInt == 8) && (player.getMoney() > 30)) {
							player.addPotion();
							cout << "You bought a potion!\n";
							isViewingItem = false;
							player.removeMoney(30);
						}
						else if(player.getMoney() >= shop.itemPrice(tempInt)){
							player.removeMoney(shop.itemPrice(tempInt));
							if (shop.isWeapon(tempInt)) {
								player.giveItem(shop.buyItem(tempInt));
							}
							else {
								player.giveArmor(shop.buyItem(tempInt));
							}
							isViewingItem = false;
						}
						else { cout << "You don't have enough money for that!" << endl; isViewingItem = 0; }

					}
					else {
						isViewingItem = false;
					}
				}

			}
			cout << "\n\n\n\n";

		}
		else if (userInput == "3") {
			//VIEW PLAYER STATS
			cout << "\t\t Your stats" << endl;
			player.printStats();
			cout << "\n\n\t\tEnter anything to return" << endl;
			isViewing = true;
			while (isViewing) {
				cin >> userInput;
				if (userInput != "") {
					isViewing = false;
				}
			}
			cout << "\n\n\n\n";
			
		}
		else if (userInput == "4") {
			//VIEW NEXT MATCH
			cout << "\t\t Your next match" << endl;
			grunt.printStats();
			cout << "\n\n\t\tEnter anything to return" << endl;
			isViewing = true;
			while (isViewing) {
				cin >> userInput;
				if (userInput != "") {
					isViewing = false;
				}
			}
			cout << "\n\n\n\n";
			
		}
		else if (userInput == "5") {
			//ENTER NEXT MATCH
			player.addMoney(arena.doCombat(player, grunt));
			cout << "Enter anything to continue.\n";
			cin >> userInput;
			cout << "\n\n\n";
			//after match, randomize enemy items IF it is not the second round.
			//and give enemy more health after first ever round.
			if (firstMatch) {
				grunt.modBaseHealth(40);
				firstMatch = false;
			}
			else {
				randInt = rand() % 5; 
				grunt.equipItem(grunt.pullItem(randInt));
				randInt = (rand() % 5) + 5;
				grunt.equipArmor(grunt.pullItem(randInt));

			}
		}
		else if (userInput == "0") {
			//QUIT
			cout << "\n\n\t\tWould you like to save your progress? (y/n)\n";
			cin >> userInput;
			if (userInput == "y") {
				ofstream file;
				file.open("save.txt", std::ofstream::out | std::ofstream::trunc);
				file.close();
				file.open("save.txt", ios::out | ios::in);
				//PLAYER INFO
				file << player.outItemInv() << "." << "\n";
				file << player.getActiveItemName() << "." << "\n";
				file << player.outArmorInv() << "." << "\n";
				file << player.getActiveArmorName() << "." << "\n";
				file << player.outPotCount() << "." << "\n";
				file << player.outGoldCount() << "." << "\n";
				//ENEMY INFO
				file << grunt.getActiveItemName() << "." << "\n";
				file << grunt.getActiveArmorName() << "." <<	"\n";

				file.close();
				cout << "\nProgress saved.\n\n";
			}
			gaming = false;
		}
		else { cout << "\tInvalid Command!\n\n"; }
	}
}