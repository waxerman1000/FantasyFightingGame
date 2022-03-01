//Andrew Green
#include "LongSword.h"

LongSword::LongSword()
{
	this->fillStats("LongSword", "A basic, rusty sword, which has no special passive.\n"
		"Due to the rust though, it has a high crit chance.\n"
		"Ok against most targets.\n", 0, 0, 25, 0, 90, 50, 0);
}

int LongSword::procPassive(int enemyHealth, int enemyDamageResist)
{
	//cout << "\t\t\tentered LongSword proc\n"; //TEMP
	tempDamage = getDamage();
	srand(time(NULL));
	tempRand = (rand() % 100);
	//cout << "\t\t\tCC, tempRand \t" << getCritChance() << ", " << tempRand << endl;
	if (getCritChance() >= tempRand) {
		cout << "CRIT!" << endl;
		tempDamage *= 2;
		tempDamage -= enemyDamageResist;
		//cout << "\tLongSword ProcPassive returning " << tempDamage << endl; //TEMP
		return tempDamage;
	}
	else { tempDamage -= enemyDamageResist;  return tempDamage; } //TEMP
}
