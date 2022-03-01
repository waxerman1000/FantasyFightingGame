//Andrew Green
#include "ImmortalShieldbow.h"

ImmortalShieldbow::ImmortalShieldbow()
{
	this->fillStats("Immortal Shieldbow", "The Immortal Shieldbow is a crossbow with a small barrier on the front.\n"
		"Every bolt fired heals you for 20% of the damage dealt.\n"
		"Great for targets with a lot of health.\n", 0, 0, 30, 0, 95, 10, 140);
}

int ImmortalShieldbow::procPassive(int enemyHealth, int enemyDamageResist)
{
	return 0;
}
