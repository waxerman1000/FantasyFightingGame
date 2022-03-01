//Andrew Green
#ifndef LONGSWORD_H
#define LONGSWORD_H
#include "Item.h"

class LongSword : public Item {
private:

	int passiveCounter = 0;
public:
	LongSword();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif