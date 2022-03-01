//Andrew Green
#ifndef WARMOGS_H
#define WARMOGS_H
#include "Item.h"

class Warmogs : public Item {
private:

	int passiveCounter = 0;
public:
	Warmogs();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif