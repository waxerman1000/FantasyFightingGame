//Andrew Green
#ifndef CLOTHARMOR_H
#define CLOTHARMOR_H
#include "Item.h"

class ClothArmor : public Item {
private:

	int passiveCounter = 0;
public:
	ClothArmor();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif