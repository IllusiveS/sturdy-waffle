//
// Created by wysockipatryk on 12/26/16.
//

#include "Game.h"

void Game::UpdateInput() {

}

Game::Game() : mainRenderer() {
	mainWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
	mainRenderer = SDL_CreateRenderer( mainWindow, -1, SDL_RENDERER_ACCELERATED );
	textureManager = new TextureManager(mainRenderer);
	//TODO stworzenie managerów inputu i tekstur
}

Game::~Game() {
	delete textureManager;
}

void Game::UpdateTick() {

}

void Game::UpdatePhysics() {

}

void Game::Render() {

}
