//Andrew Green
#include "BlackCleaver.h"

BlackCleaver::BlackCleaver()
{
	{
		this->fillStats("Black Cleaver", "The Black Cleaver is.. well.. a black cleaver. This item shreds enemy armor\n"
			"by 5 up to 20 based on consecutive attacks. \n"
			"Great for targets with a lot of armor.\n", 0, 0, 25, 0, 90, 15, 230);
	}
}

int BlackCleaver::procPassive(int enemyHealth, int enemyDamageResist)
{
	return 0;
}
