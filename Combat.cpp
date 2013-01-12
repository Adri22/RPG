#include "Combat.hpp"


Combat::Combat() {}

Combat::~Combat() {}

void Combat::PlayerAttack()
{
	// not finished
	//

	int enemies = 0;
	list<Enemy*>::iterator It;
	eList = g_pGame->getEnemyList();

	for(It = eList.begin(); It != eList.end(); ++It)
	{
		// test
		// just trying to remove hp from all enemies by attacking
		//
		float hp = (*It)->getCurrentHP();
		hp = hp - 51; // test-value --> 3 attacks should kill all enemies :D
		(*It)->setCurrentHP(hp);
		enemies++;

		cout << "Enemies: " << enemies << endl;
		cout << "current HP: " << (*It)->getCurrentHP() << endl;
	}

	// return the list to original enemy-list
	//
	g_pGame->setEnemyList(eList);
}

void Combat::EnemyAttack()
{
}

void Combat::CheckCollisions()
{
	// use hit- and attackboxes here to calc pixels which are same "hit" by attack and position of target
	//

}