//Andrew Green
#ifndef WHISPER_H
#define WHISPER_H
#include "Item.h"

class Whisper : public Item {
private:
	
	int passiveCounter = 0;
public:
	Whisper();
	int procPassive(int enemyHealth, int enemyDamageResist);
};







#endif