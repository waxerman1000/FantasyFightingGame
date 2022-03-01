//Andrew Green
#include "Character.h"
#include "Character.h"

int Character::getHealth()
{
	return this->health;
}

int Character::getDamageResist()
{
	return this->damageResist;
}

void Character::fillStats(string name, string desc, int baseHealth, int victoryWorth)
{
	this->name = name;
	this->desc = desc;
	this->baseHealth = baseHealth;
	this->health = baseHealth;
	this->victoryWorth = victoryWorth;
}

int Character::getMoveSpeed()
{
	return this->moveSpeed;
}

int Character::getVictoryWorth()
{
	return victoryWorth;
}

void Character::giveItem(Item item)
{
	itemInv.push_back(item);
}

void Character::addPotion()
{
	potionCount++;
}

void Character::removePotion()
{
	potionCount--;
}

int Character::attack(Character character, int consHits)
{
	int temp = this->equippedItem.procPassive(character.getHealth(), character.getDamageResist(), consHits);
	return temp;
}

bool Character::landsHit()
{
	tempRand = (rand() % 100);
	if (this->getHitRate() >= tempRand) {
		true;
	}
	else { return false; }
	
}

void Character::modBaseHealth(int num)
{
	baseHealth += num;
	health += num;
}

void Character::modHealth(int num)
{
	health += num;
}

void Character::modDamageResist(int num)
{
	damageResist += num;
}

void Character::modMoveSpeed(int num)
{
	moveSpeed += num;
}

void Character::printInventory()
{
	printingNum = 0;
	printingNumTemp = 0;
	cout << "Weapons:" << endl;
	if (itemInv.size() != 0) {
		for (int i = 0; i < itemInv.size(); i++) {
			if (printingNumTemp == 2) {
				cout << endl;
				printingNumTemp = 0;
			}
			cout << printingNum << ". " << itemInv[i].getName() << "\t";
			printingNum++;
			printingNumTemp++;
		}
	}
	cout << "\nArmors:" << endl;
	printingNumTemp = 0;
	if (armorInv.size() != 0) {
		for (int i = 0; i < armorInv.size(); i++) {
			if (printingNumTemp == 2) {
				cout << endl;
				printingNumTemp = 0;
			}
			cout << printingNum << ". " << armorInv[i].getName() << "\t";
			printingNum++;
			printingNumTemp++;
		}
	}
	cout << "\nHealth Potions: " << potionCount << endl;
}

string Character::outItemInv()
{
	string inventory = "";
	for (int i = 0; i < itemInv.size(); i++) {
		inventory += itemInv[i].getName();
		if (i != itemInv.size() - 1) {
			inventory += ", ";
		}
	}
	return inventory;
}

string Character::outArmorInv()
{
	string inventory = "";
	for (int i = 0; i < armorInv.size(); i++) {
		inventory += armorInv[i].getName();
		if (i != armorInv.size() - 1) {
			inventory += ", ";
		}
	}
	return inventory;
}

string Character::outPotCount()
{
	string potCount = "";
	potCount = to_string(potionCount);
	return potCount;
}

string Character::outGoldCount()
{
	string goldCount = "";
	goldCount = to_string(money);
	return goldCount;
}

bool Character::pullingItem(int itemNum)
{

	if (itemNum > (itemInv.size() - 1)) {
		return false;
	}
	else {
		return true;
	}
}

Item Character::pullItem(int itemNum)
{
	Item item;
	if (itemNum > (itemInv.size() - 1)) {
		itemNum -= itemInv.size();
		item = armorInv[itemNum];
		return item;
	}
	else {
		item = itemInv[itemNum];
		return item;
	}
}

void Character::equipItem(Item item)
{
	if (itemInv.size() != 1) {
		removeStats(equippedItem);
		equippedItem = item;
		applyStats(item);


	}
	else {
		applyStats(item);
		equippedItem = item;
	}
}

void Character::equipArmor(Item armor)
{
	
	if (armorInv.size() != 1) {
		removeStats(equippedArmor);
		equippedArmor = armor;
		applyStats(armor);
	}
	else {
		applyStats(armor);
		equippedArmor = armor;
	}
}

int Character::findArmor(string str)
{
	//cout << str << endl;
	for (int i = 0; i < armorInv.size(); i++) {
		//cout << itemInv[i].getName();
		if (str == armorInv[i].getName()) {
			return i;
		}
	}
	cout << "COULDNT FIND ARMOR " << str << " IN INVENTORY" << endl;
	return 0;
}

Item Character::pullArmor(int itemNum)
{
	Item item;
	item = armorInv[itemNum];
	return item;
}

void Character::getItem(int itemNum)
{
	if (itemNum > (itemInv.size() - 1)) {
		itemNum -= itemInv.size();
		cout << armorInv[itemNum];
	}
	else { cout << itemInv[itemNum]; }
}

int Character::findItem(string str)
{
	//cout << str << endl;
	for (int i = 0; i < itemInv.size(); i++) {
		//cout << itemInv[i].getName();
		if (str == itemInv[i].getName()) {
			return i;
		}
	}
	cout << "COULDNT FIND ITEM " << str << " IN INVENTORY" << endl;
	return 0;
}

int Character::getMoney()
{
	return money;
}

void Character::addMoney(int amt)
{
	money += amt;
	if (money < 0) {
		money = 0;
	}
}

void Character::removeMoney(int amt)
{
	money -= amt;
	if (money < 0) {
		money = 0;
	}
}

void Character::printStats()
{
	cout << name << "\n" << desc << endl;
	cout << "Equipped item: " << equippedItem.getName() << "\tEquipped armor: " << equippedArmor.getName() << endl;
	cout << endl;
	cout << "Base Health: " << this->getBaseHealth() << endl;
	cout << "\t\tHealth\tDmg Res\tDamage\tMvmt\tHitRate\tcritChance" << endl;
	cout << "Weapon Stats:\t" << equippedItem.getHealth() << "\t" << equippedItem.getDamageResist() << ""
		"\t" << equippedItem.getDamage() << "\t" << equippedItem.getMoveSpeed() << ""
		"\t" << equippedItem.getHitRate() << "\t" << equippedItem.getCritChance() << endl;
	cout << "Armor Stats:\t" << equippedArmor.getHealth() << "\t" << equippedArmor.getDamageResist() << ""
		"\t" << equippedArmor.getDamage() << "\t" << equippedArmor.getMoveSpeed() << ""
		"\t" << equippedArmor.getHitRate() << "\t" << equippedArmor.getCritChance() << endl;
	cout << "Total Stats:\t" << this->getHealth() << "\t" << this->getDamageResist() << "\t" << this->getDamage() << ""
		"\t" << this->getMoveSpeed() << "\t" << this->getHitRate() << "\t" << this->getCritChance();


}

void Character::applyStats(Item item)
{
	this->health += item.getHealth();
	this->damageResist += item.getDamageResist();
	this->damage += item.getDamage();
	this->moveSpeed += item.getMoveSpeed();
	this->hitRate += item.getHitRate();
	this->critChance += item.getCritChance();
}

void Character::removeStats(Item item)
{
	this->health -= item.getHealth();
	this->damageResist -= item.getDamageResist();
	this->damage -= item.getDamage();
	this->moveSpeed -= item.getMoveSpeed();
	this->hitRate -= item.getHitRate();
	this->critChance -= item.getCritChance();
}

void Character::giveArmor(Item armor)
{
	armorInv.push_back(armor);
}


Character::Character()
{
}

string Character::getActiveItemName()
{
	return equippedItem.getName();
}

string Character::getActiveArmorName()
{
	return equippedArmor.getName();
}


int Character::getBaseHealth()
{
	return this->baseHealth;
}

int Character::getDamage()
{
    return this->damage;
}

int Character::getHitRate()
{
	return this->hitRate;
}

int Character::getCritChance()
{
	return this->critChance;
}

