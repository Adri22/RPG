#include "Combat.hpp"


Combat::Combat() {}

Combat::~Combat() {}

void Combat::PlayerAttack()
{
	// not finished !
	//

	cout << "player_attack" << endl;

	EnemyList = g_pGame->getEnemyList();

	list<Enemy*>::iterator It;

	int enemies = 0;
	for(It = EnemyList.begin(); It != EnemyList.end(); ++It)
	{
		// test
		float hp = (*It)->getCurrentHP();
		hp = hp - 51;
		(*It)->setCurrentHP(hp);
		enemies++;
	}

	g_pGame->setEnemyList(EnemyList);

	cout << enemies << endl;
}

void Combat::EnemyAttack()
{
}
