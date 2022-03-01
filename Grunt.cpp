//Andrew Green
#include "Grunt.h"

Grunt::Grunt()
{

	ClothArmor clothArmor;
	RanduinsOmen randuinsOmen;
	ShurelyasBattlesong shurelyasBattlesong;
	SunfireAegis sunfireAegis;
	Warmogs warmogs;
	LongSword longSword;
	BlackCleaver blackCleaver;
	ImmortalShieldbow immortalShieldbow;
	PhantomDancer phantomDancer;
	Whisper whisper;

	this->fillStats("Arena Grunt.", "Also just another fool lookin for glory.", 80, 80); 
	this->giveItem(longSword);
	this->giveItem(blackCleaver);
	this->giveItem(immortalShieldbow);
	this->giveItem(phantomDancer);
	this->giveItem(whisper);
	this->equipItem(longSword);
	this->giveArmor(clothArmor);
	this->giveArmor(randuinsOmen);
	this->giveArmor(shurelyasBattlesong);
	this->giveArmor(sunfireAegis);
	this->giveArmor(warmogs);
	this->equipArmor(clothArmor);
}
