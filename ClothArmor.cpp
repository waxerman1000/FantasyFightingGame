//Andrew Green
#include "ClothArmor.h"

ClothArmor::ClothArmor()
{
	this->fillStats("Cloth Armor", "A basic wrapping of cloth and hide. Has no special passive.\n"
		"Ok against most targets.\n", 40, 7, 0, 30, 0, 0, 0);
}

int ClothArmor::procPassive(int enemyHealth, int enemyDamageResist)
{
	return 0;
}
