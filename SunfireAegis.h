//Andrew Green
#ifndef SUNFIREAEGIS_H
#define SUNFIREAEGIS_H
#include "Item.h"

class SunfireAegis : public Item {
private:

	int passiveCounter = 0;
public:
	SunfireAegis();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif