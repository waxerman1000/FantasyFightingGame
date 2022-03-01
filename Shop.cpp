//Andrew Green
#include "Shop.h"

Shop::Shop()
{
	//Create items
	RanduinsOmen randuinsOmen;
	ShurelyasBattlesong shurelyasBattlesong;
	SunfireAegis sunfireAegis;
	Warmogs warmogs;
	BlackCleaver blackCleaver;
	ImmortalShieldbow immortalShieldbow;
	PhantomDancer phantomDancer;
	Whisper whisper;

	//Put them in shop
	items.push_back(blackCleaver);
	items.push_back(immortalShieldbow);
	items.push_back(phantomDancer);
	items.push_back(whisper);

	armors.push_back(randuinsOmen);
	armors.push_back(shurelyasBattlesong);
	armors.push_back(sunfireAegis);
	armors.push_back(warmogs);
}

int Shop::findItem(string str)
{
	for (int i = 0; i < items.size(); i++) {
		if (str == items[i].getName()) {
			return i;
		}
	}
	cout << "COULDNT FIND ITEM " << str << " IN SHOP" << endl;
	return 0;
}

int Shop::findArmor(string str)
{
	for (int i = 0; i < armors.size(); i++) {
		if (str == armors[i].getName()) {
			return i;
		}
	}
	cout << "COULDNT FIND ARMOR " << str << " IN SHOP" << endl;
	return 0;
}

void Shop::displayItems()
{
	printingNum = 0;
	printingNumTemp = 0;
	cout << "Weapons:" << endl;
	if (items.size() != 0) {
		for (int i = 0; i < items.size(); i++) {
			if (printingNumTemp == 2) {
				cout << endl;
				printingNumTemp = 0;
			}
			cout << printingNum << ". " << items[i].getName() << "\t";
			printingNum++;
			printingNumTemp++;
		}
	}
	cout << "\nArmors:" << endl;
	printingNumTemp = 0;
	if (armors.size() != 0) {
		for (int i = 0; i < armors.size(); i++) {
			if (printingNumTemp == 2) {
				cout << endl;
				printingNumTemp = 0;
			}
			cout << printingNum << ". " << armors[i].getName() << "\t";
			printingNum++;
			printingNumTemp++;
		}
	}
	cout << "\n\n8. Health Potions\n";
	
}

void Shop::displayItem(int itemNum)
{
	if (itemNum == 8) {
		cout << "Health Potion\nA simple potion which can be used during combat\n"
			"to restore 35 health.\n";
	}
	else if (itemNum > (items.size() - 1)) {
		itemNum -= items.size();
		cout << armors[itemNum];
	}
	else { cout << items[itemNum]; }
}

int Shop::itemPrice(int itemNum)
{
	if (itemNum == 8) {
		return 30;
	}
	else if (itemNum > (items.size()-1)) {
		itemNum -= items.size();
		return armors[itemNum].getPrice();
	}
	else {
		return items[itemNum].getPrice();
	}
}

bool Shop::isWeapon(int itemNum)
{
	if (itemNum > (items.size() - 1)) {

		return false;
	}
	else {

		return true;
	}
}

Item Shop::giveItem(int itemNum)
{
	Item item;
	item = items[itemNum];
	items.erase(items.begin() + itemNum);
	return item;
}

Item Shop::giveArmor(int itemNum)
{
	Item item;
		item = armors[itemNum];
		armors.erase(armors.begin() + itemNum);
		return item;
}


Item Shop::buyItem(int itemNum)
{
	Item item;
	if (itemNum > (items.size() -1 ))  {
		itemNum -= items.size();
		item = armors[itemNum];
		armors.erase(armors.begin() + itemNum);
		cout << "You bought the " << item.getName() << "!\n";
		return item;
	}
	else {
		item = items[itemNum];
		items.erase(items.begin() + itemNum);
		cout << "You bought the " << item.getName() << "!\n";
		return item;
	}
}
