//Andrew Green
#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <vector>
#include <random>
#include "Character.h"


using namespace std;

class Arena {
private:
	int userConsecutiveHits = 0;
	int enemyConsecutiveHits = 0;
	int tempRand = 0;
	int tempDamage = 0;
	bool inCombat = true;
	bool enemyAlive = true;
	bool userAlive = true;
	bool userForfeit = false;
	string userInput = "";
public:
	Arena();
	int doCombat(Character user, Character enemy);


};

#endif ARENA_H