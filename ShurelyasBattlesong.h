//Andrew Green
#ifndef SHURELYASBATTLESONG_H
#define SHURELYASBATTLESONG_H
#include "Item.h"

class ShurelyasBattlesong : public Item {
private:

	int passiveCounter = 0;
public:
	ShurelyasBattlesong();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif