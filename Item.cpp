//Andrew Green
#include "Item.h"

Item::Item()
{
	srand(time(NULL));
}

string Item::getName()
{
	return name;
}

string Item::getDesc()
{
	return desc;
}

int Item::getDamage()
{
	return damage;
}

int Item::getMoveSpeed()
{
	return moveSpeed;
}

int Item::getHitRate()
{
	return hitRate;
}

int Item::getCritChance()
{
	return critChance;
}

int Item::getPrice()
{
	return price;
}

int Item::getHealth()
{
	return health;
}

int Item::getDamageResist()
{
	return damageResist;
}

int Item::procPassive(int enemyHealth, int enemyDamageResist, int consHits)
{
	//cout << "\t\t\t\t\tENTERING ITEM PROC, NOT WEAPON" << endl;
	if (name == "LongSword") {
		//cout << "\t\t\tentered LongSword proc\n"; //TEMP
		tempDamage = getDamage();
		tempRand = (rand() % 100);
		//cout << "\t\t\tCC, tempRand \t" << getCritChance() << ", " << tempRand << endl;
		if (getCritChance() >= tempRand) {
			cout << "CRIT!" << endl;
			tempDamage *= 2;
			tempDamage -= enemyDamageResist;
			//cout << "\tLongSword ProcPassive returning " << tempDamage << endl; //TEMP
			return tempDamage;
		}
		else { tempDamage -= enemyDamageResist;  return tempDamage; } 
	}
	else if (name == "Black Cleaver") {
		tempDamage = getDamage();
		
		if ((consHits == 0) && (passiveProcing == true)) {
			tempNum = 5;
			passiveProcing = false;
		}
		else if ((consHits == 0) && (passiveProcing == false)) {
			tempNum = 5;
			passiveProcing = true;
		}
		else {
			tempNum += 5;
			if (tempNum >= enemyDamageResist) {
				tempNum = enemyDamageResist;
			}
		}
		cout << "The Black Cleaver is currently shredding " << tempNum << " armor.\n";
		tempDamage += tempNum;

		tempRand = (rand() % 100);
		//cout << "\t\t\tCC, tempRand \t" << getCritChance() << ", " << tempRand << endl;
		if (getCritChance() >= tempRand) {
			cout << "CRIT!" << endl;
			tempDamage *= 2;
			tempDamage -= enemyDamageResist;
			//cout << "\tLongSword ProcPassive returning " << tempDamage << endl; //TEMP
			return tempDamage;
		}
		else { tempDamage -= enemyDamageResist;  return tempDamage; }
	}
	else if (name == "Immortal Shieldbow") {
		tempDamage = getDamage();
		tempRand = (rand() % 100);
		if (getCritChance() >= tempRand) {
			cout << "CRIT!" << endl;
			tempDamage *= 2;
			tempDamage -= enemyDamageResist;
			return tempDamage;
		}
		else { tempDamage -= enemyDamageResist;  return tempDamage; }
	}
	else if (name == "Phantom Dancer") {
		tempDamage = getDamage();
		tempRand = (rand() % 100);
		//cout << "\t\t\tCC, tempRand \t" << getCritChance() << ", " << tempRand << endl;
		if (getCritChance() >= tempRand) {
			cout << "CRIT!" << endl;
			tempDamage *= 2;
			tempDamage -= enemyDamageResist;
			//cout << "\tLongSword ProcPassive returning " << tempDamage << endl; //TEMP
			if (((consHits % 2)) == 1) {
				cout << "The Phantom Dancers struck twice!";
				tempDamage *= 2;

			}
			return tempDamage;
		}
		else {
			tempDamage -= enemyDamageResist; 
			if (((consHits % 2)) == 1) {
				cout << "The Phantom Dancers struck twice!";
				tempDamage *= 2;

			}
			return tempDamage;
		}
	}
	else if (name == "Whisper") {
		if ((consHits == 0) && (tempNum != 0)) {
			tempNum++;
		}
		tempNum ++;
		if (tempNum < 4) {
			//is before fourth shot
			if (tempNum == 0) {
				cout << "how did I get here?\n";
			}
			if (tempNum == 1) {
				cout << "one...\n";
			}
			if (tempNum == 2) {
				cout << "two...\n";
			}
			if (tempNum == 3) {
				cout << "three...\n";
			}
			tempDamage = getDamage();
			tempRand = (rand() % 100);
			if (getCritChance() >= tempRand) {
				cout << "CRIT!" << endl;
				tempDamage *= 2;
				tempDamage -= enemyDamageResist;
				return tempDamage;
			}
			else { tempDamage -= enemyDamageResist;  return tempDamage; }
		}
		else if (tempNum > 4) {
			//RELOAD
			cout << "Whisper is reloading, and cannot attack.\n";
			tempNum = 0;
			return 0;
		}
		else {
			//IF FOURTH SHOT
			cout << "FOUR!!!" << endl;
			tempDamage = getDamage();
			tempDamage *= 2.5;
			tempDamage -= enemyDamageResist;
			//cout << "\tLongSword ProcPassive returning " << tempDamage << endl; //TEMP
		}
		return tempDamage;
	}
	cout << "COULD NOT FIND ITEM PROC, RETURNING 20" << endl;
	return 20;
}

void Item::fillStats(string name, string desc, int health, int damageResist, int damage, int moveSpeed, int hitRate, int critChance, int price)
{
	this->name = name;
	this->desc = desc;
	this->health = health;
	this->damageResist = damageResist;
	this->damage = damage;
	this->moveSpeed = moveSpeed;
	this->hitRate = hitRate;
	this->critChance = critChance;
	this->price = price;
}
