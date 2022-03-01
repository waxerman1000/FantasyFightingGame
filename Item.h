//Andrew Green

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <math.h>

#include <random>

using namespace std;

class Item {
private:
	string name = "";
	string desc = "";
	int health = 0;
	int damageResist = 0;
	int damage = 0;
	int moveSpeed = 0;
	int hitRate = 0;
	int critChance = 0;
	int price = 0;


public:

	Item();
	int tempRand = 0;
	int tempNum = 0;
	int tempDamage = 0;
	bool passiveProcing = false;
	string getName(); 
	string getDesc();
	int getHealth();
	int getDamageResist();
	int getDamage();
	int getMoveSpeed();
	int getHitRate();
	int getCritChance();
	int getPrice();
	//below can be used to fill the stats for derived classes.
	void fillStats(string name, string desc, int health, int damageResist, int damage, int moveSpeed, int hitRate, int critChance, int price);
	//virtual function which CAN be used, but I was unable to figure out a process to properly use for this game.
	virtual int procPassive(int enemyHealth, int enemyDamageResist, int consHits);

	friend ostream& operator<<(ostream& out, const Item& rhs) {
		string temp;
		temp = rhs.name;
		temp += "\n";
		temp += rhs.desc;

		out << temp << "\nHealth\tDmg Res\tDamage\tMvmt\tHitRate\tCritChance\n" <<
			rhs.health << "\t" << rhs.damageResist << ""
			"\t" << rhs.damage << "\t" << rhs.moveSpeed << ""
			"\t" << rhs.hitRate << "\t" << rhs.critChance << endl;
		return out;
	}
};




#endif