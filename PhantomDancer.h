//Andrew Green
#ifndef PHANTOMDANCER_H
#define PHANTOMDANCER_H
#include "Item.h"

class PhantomDancer : public Item {
private:

	int passiveCounter = 0;
public:
	PhantomDancer();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif