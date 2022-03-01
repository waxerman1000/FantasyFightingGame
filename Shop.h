//Andrew Green
#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <vector>
#include "Item.h"
//ITEMS
#include "BlackCleaver.h"
#include "ImmortalShieldbow.h"
#include "PhantomDancer.h"
#include "Whisper.h"
//ARMORS
#include "RanduinsOmen.h"
#include "ShurelyasBattlesong.h"
#include "SunfireAegis.h"
#include "Warmogs.h"

using namespace std;

class Shop {
private:
	vector<Item> items;
	vector<Item> armors;
	int itemViewing = 0;
	int printingNum = 0;
	int printingNumTemp = 0;
public:
	Shop();
	int findItem(string str);
	int findArmor(string str);
	void displayItems();
	void displayItem(int itemNum);
	int itemPrice(int itemNum);
	bool isWeapon(int itemNum);
	Item giveItem(int itemNum);
	Item giveArmor(int itemNum);
	Item buyItem(int itemNum);


};

#endif SHOP_H