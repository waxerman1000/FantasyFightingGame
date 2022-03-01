//Andrew Green
#ifndef BLACKCLEAVER_H
#define BLACKCLEAVER_H
#include "Item.h"

class BlackCleaver : public Item {
private:

	int passiveCounter = 0;
public:
	BlackCleaver();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif