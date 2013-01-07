/* 
 * File:   Game.cpp
 * Author: Adrian
 * 
 * Created on 23. Dezember 2012, 18:38
 */

#include "Game.hpp"

Game::Game() 
{
	player = NULL;
	SpriteBackground = NULL;
}

Game::Game(const Game& orig) 
{
}

Game::~Game() 
{
	list<Enemy*>::iterator It;
	for(It = EnemyList.begin(); It != EnemyList.end(); ++It)
		delete (*It);
}

void Game::Init()
{
	// initialize new player
	player = new Player;
	player->Init();
	player->Reset();

	SpriteBackground = new CSprite;
	SpriteBackground->Load("Data/Background_Test.bmp");

	spawnTimer = 0.0;

	// game starts
	gameRun = true;
}

void Game::Run()
{
	// Main-Loop
	//
	while(gameRun == true)
	{
		ProcessEvents ();

		// update framework and delete buffer
		g_pFramework->Update();
		g_pFramework->Clear();

		SpriteBackground->Render();

		// update and render player
		player->Update();
		player->Render();

		SpawnEnemys();
		HandleEnemys();

		g_pFramework->Flip();
	}
}

void Game::Quit()
{
	if(player != NULL)
	{
		player->Quit();
		delete(player);
		player = NULL;
	}

	if(SpriteBackground != NULL)
	{
		delete(SpriteBackground);
		SpriteBackground = NULL;
	}
}

void Game::ProcessEvents()
{
	SDL_Event Event;

	if(SDL_PollEvent(&Event))
	{
		switch(Event.type)
		{
			case SDL_QUIT:
				gameRun = false;
				break;

			case SDL_KEYDOWN:
				switch(Event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						gameRun = false;
						break;
				}
				break;
		}
	}
}

void Game::SpawnEnemys()
{
	spawnTimer += g_pTimer->GetElapsed();

	if(spawnTimer >= 1.0)
	{
		Enemy* enemy = new Enemy();
		enemy->Init();
		enemy->Reset();

		EnemyList.push_back(enemy);

		spawnTimer = 0.0;
	}
}

void Game::HandleEnemys()
{
	list<Enemy*>::iterator It;

	for(It = EnemyList.begin(); It != EnemyList.end(); ++It)
	{
		(*It)->Render();
		(*It)->Update();
	}
}

void Game::CheckCollisions()
{
}