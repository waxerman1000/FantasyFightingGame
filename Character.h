//Andrew Green

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <random>
#include <string>
#include "Item.h"
//ITEMS
#include "BlackCleaver.h"
#include "ImmortalShieldbow.h"
#include "LongSword.h"
#include "PhantomDancer.h"
#include "Whisper.h"
//ARMORS
#include "ClothArmor.h"
#include "RanduinsOmen.h"
#include "ShurelyasBattlesong.h"
#include "SunfireAegis.h"
#include "Warmogs.h"



using namespace std;

class Character {
private:
	vector<Item> itemInv;
	Item equippedItem;
	vector<Item> armorInv;
	Item equippedArmor;
	int potionCount = 1;
	int tempRand = 0;
	string name = "";
	string desc = "";
	int baseHealth = 0;
	int damage = 0;
	int health = 0;
	int damageResist = 0;
	int moveSpeed = 0;
	int hitRate = 0;
	int critChance = 0;
	int money = 100;
	int victoryWorth = 0;
	int activeHealth = 0;

public:
	Character();
	string getActiveItemName();
	string getActiveArmorName();
	int getBaseHealth();
	int getHealth();
	int getDamage();
	int getHitRate();
	int getCritChance();
	int getDamageResist();
	int getMoveSpeed();
	int getVictoryWorth();
	int getMoney();
	void addMoney(int amt);
	void removeMoney(int amt);
	void addPotion();
	void removePotion();
	int attack(Character character, int consHits);
	bool landsHit();
	void modBaseHealth(int num);
	void modHealth(int num);
	void modDamageResist(int num);
	void modMoveSpeed(int num);

	int printingNum = 0;
	int printingNumTemp = 0;

	void applyStats(Item item);
	void removeStats(Item item);

	void giveItem(Item item);
	void equipItem(Item item);
	void getItem(int num);
	int findItem(string str);
	Item pullItem(int itemNum);
	bool pullingItem(int itemNum);
	void giveArmor(Item armor);
	void equipArmor(Item armor);
	int findArmor(string str);
	Item pullArmor(int itemNum);
	void printStats();
	void printInventory();
	string outItemInv();
	string outArmorInv();
	string outPotCount();
	string outGoldCount();
	void fillStats(string name, string desc, int baseHealth, int victoryWorth);

	friend ostream& operator<<(ostream& out, const Character& rhs) {
		string temp;
		temp = rhs.name;
		temp += "\n";
		temp += rhs.desc;
		out << temp;
		return out;
	}
};




#endif