#include <iostream>

using namespace std;

//Enemy1
int enemyHp = 200;
int enemyDmg;
string enemyNm = "ZAPS";
bool enemyStatus = true;

//Enemy2
int enemy2Hp = 200;
int enemy2Dmg;
string enemy2Nm = "SPAZ";
bool enemy2Status = true;

//Hero
int heroHp = 500;
string heroNm;
bool heroStatus = true;
int basicHit;
int critHit;
int hit;
int combo;
int magic;
int basicCrit;

//Game
int xMagic = 3;
bool keepGame = true;
string choose;
int finalChoose;
string attack;

void gameStart() {
	cout << "Wo: Hi traveler my name is Wo, tell me your name -  ";
	cin >> heroNm;
	cout << "\n";
	cout << "Wo: Nice {" << heroNm << "} let's begin with your first fight!\n\n";
	cout << "---------------------------------------\n";
	cout << "First FIGHT VS " << enemyNm << " and " << enemy2Nm << " Just Begun\n";
	cout << "---------------------------------------\n\n";
}
bool heroAlive() {
	if (heroHp <= 0)
	{
		cout << "\nWo: Damn you died {" << heroNm << "}, maybe next time!\n\n";
		cout << "---------------------------------------\n";
		cout << "              GAME OVER\n";
		cout << "---------------------------------------\n";
		return false;
	}
	else
	{
		return true;
	}
}
bool checkEnemyAlive(int enemyHP) {
	if (enemyHP <= 0)
	{
		return false;
	}
	else {
		return true;
	}
}
bool bothStatus() {
	if (enemyStatus == false && enemy2Status == false)
	{
		cout << "\nWo: Very Nice {" << heroNm << "} You WON the FIGHT\n\n";
		cout << "---------------------------------------\n";
		cout << "            CONGRATULATIONS\n";
		cout << "---------------------------------------\n";
		return false;
	}
	else {
		return true;
	}
}
int chooseWhoAttack() {
	choose = "";
	if (enemyStatus && enemy2Status && heroStatus)
	{
		while (choose != "1" &&  choose != "2")
		{
			cout << "Choose an enemy to attack [1]Zaps [2]Spaz - ";
			cin >> choose;
		}
		if (choose == "1")
		{
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (enemyStatus == true && enemy2Status == false && heroStatus)
	{
		while (choose != "1")
		{
			cout << enemyNm << " is the only one standing still [1] - ";
			cin >> choose;
		}
		return 1;
	}
	else if (enemyStatus == false && enemy2Status == true && heroStatus)
	{
		while (choose != "2")
		{
			cout << enemy2Nm << " is the only one standing still [2] - ";
			cin >> choose;
		}
		return 2;
	}
}
void chooseAttack() {
	attack = "";
	if (xMagic == 0)
	{
		while (attack != "hit" && attack != "combo")
		{
			cout << "Your turn, use an attack (hit/combo) - ";
			cin >> attack;
		}
	}
	else {
		while (attack != "hit" && attack != "combo" && attack != "magic")
		{
			cout << "Your turn, use an attack (hit/combo/magic) - ";
			cin >> attack;
		}
	}
}
void basicOrCrit() {
	basicCrit = rand() % (1,3);

	if (basicCrit == 1)
	{
		hit = basicHit;
	}
	else
	{
		hit = critHit;
	}

}
void attackEnemy(int& enemysHp, int& herosHp, string& enemysNm) {
	if (attack == "hit")
	{

			enemysHp -= hit;
			if (basicCrit == 1)
			{
				cout << "\nWo: You hit a normal hit of " << hit << " damage! ";
				if (enemysHp < 0)
				{
					cout << enemysNm << " has 0 HP!\n";
				}
				else
				{
					cout << enemysNm << " has " << enemysHp << " HP!\n";
				}
				}
				
			else
			{
				cout << "\nWo: You hit a Critical hit of " << hit << " damage! ";
				if (enemysHp < 0)
				{
					cout << enemysNm << " has 0 HP!\n";
				}
				else
				{
					cout << enemysNm << " has " << enemysHp << " HP!\n";
				}
			}

			if (enemyHp > 0)
			{
				herosHp -= enemyDmg;
				cout << "Wo: " << enemysNm << "'s turn! ";
				cout << "It hits you with " << enemyDmg << " DMG!\n";
			}
			if (enemy2Hp > 0)
			{
				herosHp -= enemy2Dmg;
				cout << "Wo: " << enemy2Nm << "'s turn! ";
				cout << "It hits you with " << enemy2Dmg << " DMG!\n";
			}
			if ((enemyHp > 0) || (enemy2Hp > 0))
			{
				cout << "Wo: Now you have " << heroHp << " HP!\n\n";
			}
		
	}
	else if (attack == "combo")
	{

			enemysHp -= combo;
			cout << "\nWo: You hit a combo of " << combo << " damage! ";
			if (enemysHp < 0)
			{
				cout << enemysNm << " has 0 HP!\n";
			}
			else
			{
				cout << enemysNm << " has " << enemysHp << " HP!\n";
			}

			if (enemyHp > 0)
			{
				herosHp -= enemyDmg;
				cout << "Wo: " << enemysNm << "'s turn! ";
				cout << "It hits you with " << enemyDmg << " DMG!\n";
			}
			if (enemy2Hp > 0)
			{
				herosHp -= enemy2Dmg;
				cout << "Wo: " << enemy2Nm << "'s turn! ";
				cout << "It hits you with " << enemy2Dmg << " DMG!\n";
			}
			if ((enemyHp > 0) || (enemy2Hp > 0))
			{
				cout << "Wo: Now you have " << heroHp << " HP!\n\n";
			}
		
	}
	else if (attack == "magic")
	{

			enemysHp -= magic;
			cout << "\nWo: You hit a magic spell of " << magic << " damage! ";
			if (enemysHp < 0)
			{
				cout << enemysNm << " has 0 HP!\n";
			}
			else
			{
				cout << enemysNm << " has " << enemysHp << " HP!\n";
			}

			if (enemyHp > 0)
			{
				herosHp -= enemyDmg;
				cout << "Wo: " << enemyNm << "'s turn! ";
				cout << "It hits you with " << enemyDmg << " DMG!\n";
			}
			if (enemy2Hp > 0)
			{
				herosHp -= enemy2Dmg;
				cout << "Wo: " << enemy2Nm << "'s turn! ";
				cout << "It hits you with " << enemy2Dmg << " DMG!\n";
			}
			if ((enemyHp > 0) || (enemy2Hp > 0))
			{
				cout << "Wo: Now you have " << heroHp << " HP!\n\n";
			}
		
		xMagic--;
	}
}

void game() {

	gameStart();
	while (keepGame && heroStatus)
	{
		basicHit = rand() % 11 + 30;
		magic = rand() % 41 + 80;
		combo = rand() % 21 + 50;
		critHit = rand() % 21 + 40;
		enemyDmg = rand() % 70 + 30;
		enemy2Dmg = rand() % 70 + 30;

		
		heroStatus = heroAlive();
		enemyStatus = checkEnemyAlive(enemyHp);
		enemy2Status = checkEnemyAlive(enemy2Hp);
		keepGame = bothStatus();
		finalChoose = chooseWhoAttack();
		if (keepGame && heroStatus)
		{
			chooseAttack();
			basicOrCrit();
			if (finalChoose == 1)
			{
				attackEnemy(enemyHp, heroHp, enemyNm);
			}
			else
			{
				attackEnemy(enemy2Hp, heroHp, enemy2Nm);
			}
		}
		
	}
}

int main() 
{
	game();
}
