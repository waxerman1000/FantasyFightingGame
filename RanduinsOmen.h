//Andrew Green
#ifndef RANDUINSOMEN_H
#define RANDUINSOMEN_H
#include "Item.h"

class RanduinsOmen : public Item {
private:

	int passiveCounter = 0;
public:
	RanduinsOmen();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif