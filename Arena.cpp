//Andrew Green
#include "Arena.h"

Arena::Arena()
{
}

int Arena::doCombat(Character user, Character enemy)
{
	userConsecutiveHits = 0;
	enemyConsecutiveHits = 0;
	tempRand = 0;
	tempDamage = 0;
	userAlive = true;
	enemyAlive = true;
	userForfeit = false;
	srand(time(NULL));
	//enemy introduction
	cout << "\n\n\n\n\n\n\n\n\n\t\tYou enter the Arena!!\n";
	cout << "Grunt: ";
	tempRand = (rand() % 4);
	if (tempRand == 0) { cout << "Who sends babies to fight me?\n*Baby? You're 25. Maybe they're blind...*" << endl;; }
	else if (tempRand == 1) { cout << "This'll be a slaughter!\n*How can they slaughter you? You're not a lamb.*" << endl; }
	else if (tempRand == 2) { cout << "Our performance, begins.\n*You forgot to practice your lines.*" << endl; }
	else if (tempRand == 3) { cout << "Keep a man down long enough, and the gutter becomes his kingdom.\n"
		"*You notice they're standing*" << endl; }
	cout << endl;
	
	while (userAlive && enemyAlive && !userForfeit) {
		cout << "Combat time! What will you do?" << endl;
		//Print opponent status
		if (enemy.getHealth() > 150) { cout << "The enemy looks ok.\n"; }
		else if (enemy.getHealth() > 100) { cout << "The enemy looks slightly scuffed.\n"; }
		else if (enemy.getHealth() > 60) { cout << "The enemy looks hurt.\n"; }
		else if (enemy.getHealth() > 20) { cout << "The enemy looks ready to fall.\n"; }
		else if (enemy.getHealth() > 0) { cout << "How are they still able to stand?\n"; }
		cout << "You have " << user.getHealth() << " health remaining." << endl;
		if (user.getMoveSpeed() >= enemy.getMoveSpeed()) {
			cout << "You're currently faster, so your attack will hit first." << endl;
		}
		else { cout << "You're currently slower, so your attack will hit second." << endl; }
		cout << "0. Attack\n1. Defend\n2. Heal\n3. Forfeit\n";
		cin >> userInput;
		cout << "\n\n\n\n\n\n\n\n\n";
		if (userInput == "0") {
			//Player attacks!
			if (user.getMoveSpeed() >= enemy.getMoveSpeed()) {
				//USER IS FASTER OR EVEN
				//User turn
				cout << "You attack!\n";
				if (user.landsHit()) {
					tempDamage = user.attack(enemy, userConsecutiveHits);
					userConsecutiveHits++;
					cout << "You dealt " << tempDamage << " damage!" << endl;
					//cout << "\t\t User consecutive hits: " << userConsecutiveHits << endl;
					enemy.modHealth(tempDamage * -1);
					if (enemy.getHealth() <= 0) {
						enemyAlive = false;
					}
					//if damage was dealt by shieldbow
					if (user.getActiveItemName() == "Immortal Shieldbow") {
						tempDamage *= 0.2;
						cout << "The shieldbow healed you for " << tempDamage << "!\n";
						user.modHealth(tempDamage);
					}
				}
				else { cout << "But you miss!\n"; userConsecutiveHits = 0; }

				//Enemy turn
				cout << "The grunt attacks!\n";
				if (enemy.landsHit()) {
					tempDamage = enemy.attack(user, enemyConsecutiveHits);
					enemyConsecutiveHits++;
					cout << "They hit you for " << tempDamage << " damage!" << endl;
					//cout << "\t\t Enemy consecutive hits: " << enemyConsecutiveHits << endl;
					user.modHealth(tempDamage * -1);
					if (user.getHealth() <= 0) {
						userAlive = false;
					}
					//if damage was dealt by shieldbow
					if (enemy.getActiveItemName() == "Immortal Shieldbow") {
						tempDamage *= 0.2;
						cout << "The shieldbow healed them for " << tempDamage << "!\n";
						enemy.modHealth(tempDamage);
					}
				}
				else { cout << "But they miss!\n"; enemyConsecutiveHits = 0; }
			}
			else {
				//ENEMY IS FASTER
				//Enemy turn
				cout << "The grunt attacks!\n";
				if (enemy.landsHit()) {
					tempDamage = enemy.attack(user, enemyConsecutiveHits);
					enemyConsecutiveHits++;
					cout << "They hit you for " << tempDamage << " damage!" << endl;
					//cout << "\t\t Enemy consecutive hits: " << enemyConsecutiveHits << endl;
					user.modHealth(tempDamage * -1);
					if (user.getHealth() <= 0) {
						userAlive = false;
					}
					//if damage was dealt by shieldbow
					if (enemy.getActiveItemName() == "Immortal Shieldbow") {
						tempDamage *= 0.2;
						cout << "The shieldbow healed them for " << tempDamage << "!\n";
						enemy.modHealth(tempDamage);
					}
				}
				else { cout << "But they miss!\n"; enemyConsecutiveHits = 0; }
				//User turn
				cout << "You attack!\n";
				if (user.landsHit()) {
					tempDamage = user.attack(enemy, userConsecutiveHits);
					userConsecutiveHits++;
					cout << "You dealt " << tempDamage << " damage!" << endl;
					//cout << "\t\t User consecutive hits: " << userConsecutiveHits << endl;
					enemy.modHealth(tempDamage * -1);
					if (enemy.getHealth() <= 0) {
						enemyAlive = false;
					}
					//if damage was dealt by shieldbow
					if (user.getActiveItemName() == "Immortal Shieldbow") {
						tempDamage *= 0.2;
						cout << "The shieldbow healed you for " << tempDamage << "!\n";
						user.modHealth(tempDamage);
					}
				}
				else { cout << "But you miss!\n"; userConsecutiveHits = 0; }
			}
		}
		else if (userInput == "1") {
			//Player defends!
			cout << "You defend!\n";
			userConsecutiveHits = 0;
			cout << "The grunt attacks!\n";
			if (enemy.landsHit()) {
				//cout << "\tEnemy lands hit, entering enemy.attack" << endl; //TEMP
				tempDamage = enemy.attack(user, enemyConsecutiveHits);
				//cout << "\tenemy.attack returned with " << tempDamage << endl; //TEMP
				tempDamage = tempDamage / 8;
				cout << "But because you braced yourself, they only did " << tempDamage << " damage!\n";
				enemyConsecutiveHits++;
				tempDamage *= -1;
				user.modHealth(tempDamage);
				//if damage was dealt by shieldbow
				if (enemy.getActiveItemName() == "Immortal Shieldbow") {
					tempDamage *= 0.2;
					cout << "The shieldbow healed them for " << tempDamage << "!\n";
					enemy.modHealth(tempDamage);
				}
			}
			else {
				cout << "But they miss!\n";
				enemyConsecutiveHits = 0;
			}
			
			
		}
		else if (userInput == "2") {
			//Player drinks a health pot!
			cout << "You drink a health potion!\n";
			if (stoi(user.outPotCount()) > 0) {
				user.modHealth(35);
				user.removePotion();
			}
			else {
				cout << "But you don't have any more left!!" << endl;
			}
			

			//Enemy turn
			cout << "The grunt attacks!\n";
			if (enemy.landsHit()) {
				tempDamage = enemy.attack(user, enemyConsecutiveHits);
				enemyConsecutiveHits++;
				cout << "They hit you for " << tempDamage << " damage!" << endl;
				//cout << "\t\t Enemy consecutive hits: " << enemyConsecutiveHits << endl;
				user.modHealth(tempDamage * -1);
				if (user.getHealth() <= 0) {
					userAlive = false;
				}
				//if damage was dealt by shieldbow
				if (enemy.getActiveItemName() == "Immortal Shieldbow") {
					tempDamage *= 0.2;
					cout << "The shieldbow healed them for " << tempDamage << "!\n";
					enemy.modHealth(tempDamage);
				}
			}
			else { cout << "But they miss!\n"; enemyConsecutiveHits = 0; }
		}
		else if (userInput == "3") {
			//Player... forfeits?
			userForfeit = true;
		}
		cout << endl;
		
	}
	if (enemyAlive == false) {
		cout << "You won!" << endl;
		cout << "You won " << 80 << " gold!\n";
		return 80;
	}
	else if (userAlive == false) {
		cout << "you got knocked out!" << endl;
		cout << "You lost " << 60 << " gold!\n";
		return 60;
	}
	else if (userForfeit == true) {
		cout << "You forfeit." << endl;
		cout << "You lost " << 30 << " gold!\n";
		return 30;
	}


}
