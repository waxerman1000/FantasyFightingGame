//Andrew Green
#include "Player.h"

Player::Player()
{
	ClothArmor clothArmor;
	LongSword longSword;
	this->fillStats("You.", "Just another fool lookin for glory.", 180, 80);
	this->giveItem(longSword);
	this->equipItem(longSword);
	this->giveArmor(clothArmor);
	this->equipArmor(clothArmor);
}
