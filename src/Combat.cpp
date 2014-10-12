#include "Combat.hpp"

Combat::Combat() {
	collision = false;
}

Combat::~Combat() {
}

void Combat::PlayerAttack() {
	CheckCollisions(PLAYER);

	list<Enemy*>::iterator It;
	eList = g_pGame->getEnemyList();

	for (It = eList.begin(); It != eList.end(); ++It) {
		if ((*It)->getHit()) {
			float hp = (*It)->getCurrentHP();
			hp -= g_pPlayer->getDMG();
			(*It)->setCurrentHP(hp);
			(*It)->setHit(false);

			cout << "Enemy-HP: " << (*It)->getCurrentHP() << endl;
		}
	}

	// return the list to original enemy-list
	//
	g_pGame->setEnemyList(eList);
}

void Combat::EnemyAttack() {
}

void Combat::CheckCollisions(int whoisattacking) {
	collision = false;
	list<Enemy*>::iterator It;
	eList = g_pGame->getEnemyList();

	// player is attacking
	//
	if (whoisattacking == PLAYER) {
		for (It = eList.begin(); It != eList.end(); ++It) {
			if (g_pPlayer->player_atk_box.left >= (*It)->enemy.left &&
			(g_pPlayer->player_atk_box.right - (*It)->enemy.right) <= (*It)->enemy.width ||
			g_pPlayer->player_atk_box.right <= (*It)->enemy.right &&
			((*It)->enemy.left - g_pPlayer->player_atk_box.left) <= (*It)->enemy.width
			)
			if (g_pPlayer->player_atk_box.top >= (*It)->enemy.bottom &&
			g_pPlayer->player_atk_box.bottom <= (*It)->enemy.bottom ||
			g_pPlayer->player_atk_box.bottom >= (*It)->enemy.top &&
			g_pPlayer->player_atk_box.top <= (*It)->enemy.top
			)
			collision = true;

			if (collision) {
				(*It)->setHit(true);
				collision = false;
			}
		}
	}

	// enemy is attacking
	//
	if (whoisattacking == ENEMY) {
		// insert collision-checking by enemy-attacking here
	}
}
