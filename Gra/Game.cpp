//
// Created by wysockipatryk on 12/26/16.
//

#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

void Game::UpdateInput() {

}

Game::Game() : mainRenderer() {
	if(!init()) {
		printf("[err]cant initialize SDL \n");
	} else {
		printf("[suc]SDL initialized \n");
	}
	SDL_Surface * surface = SDL_GetWindowSurface(mainWindow);
	if(surface == NULL) {
		printf("[err]ERROR: %s \n", SDL_GetError());
	}
	textureManager = new TextureManager(mainRenderer, surface);
	//TODO stworzenie managerów inputu i tekstur
}

Game::~Game() {
	delete textureManager;
}



bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		mainWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0 );
		if( mainWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			mainRenderer = SDL_CreateRenderer( mainWindow, -1, SDL_RENDERER_ACCELERATED );
			if( mainRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

void Game::UpdateTick() {

}

void Game::UpdatePhysics() {

}

void Game::Render() {

}
