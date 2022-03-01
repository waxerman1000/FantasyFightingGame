//Andrew Green
#ifndef IMMORTALSHIELDBOW_H
#define IMMORTALSHIELDBOW_H
#include "Item.h"

class ImmortalShieldbow : public Item {
private:

	int passiveCounter = 0;
public:
	ImmortalShieldbow();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif