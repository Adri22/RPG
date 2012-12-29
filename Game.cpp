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
}

Game::Game(const Game& orig) 
{
}

Game::~Game() 
{
}

void Game::Init()
{
	// initialize new player
	player = new Player;
	player->Init();
	player->Reset();

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

		// update and render player
		player->Update();
		player->Render();

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