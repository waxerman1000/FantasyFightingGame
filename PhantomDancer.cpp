//Andrew Green
#include "PhantomDancer.h"

PhantomDancer::PhantomDancer()
{
	this->fillStats("Phantom Dancer", "The Phantom Dancers are sickles that have a very high\n"
		"hit rate. After two consecutive hits on an enemy, you strike\n"
		"again.\n"
		"Great for targets with high movement speed.\n", 0, 0, 30, 10, 95, 5, 200);
}

int PhantomDancer::procPassive(int enemyHealth, int enemyDamageResist)
{
	return 0;
}
