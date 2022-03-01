//Andrew Green
#include "Whisper.h"



Whisper::Whisper()
{
	this->fillStats("Whisper", "Whisper can only fire four shots before needing to be reloaded. The\n"
		"fourth shot however, always critically strikes for an\n"
		"extra 150% damage.\n"
		"Great for targets with little health.\n", 0, 0, 35, 0, 90, 5, 300);
}


int Whisper::procPassive(int enemyHealth, int enemyDamageResist)
{
	return 0;
}
