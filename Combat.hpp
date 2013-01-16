#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <iostream>
#include <list>
#include <vector>
#include "Singleton.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Game.hpp"

using namespace std;

#define g_pCombat Combat::Get()

enum WHOISATTACKING
{
    PLAYER,
    ENEMY
};

class Combat : public TSingleton<Combat>
{
	public:
		Combat();
		virtual ~Combat();

		void		PlayerAttack		();
		void		EnemyAttack			();

	private:
		void			CheckCollisions	(int whoisattacking);

		bool			collision;
		list<Enemy*>	eList;
		vector<int>		Player_HitBox_Positions;
		vector<int>		Player_AtkBox_Positions;
		vector<int>		Enemy_HitBox_Positions;
		// vector<int>			Enemy_AtkBox_Positions;
};

#endif