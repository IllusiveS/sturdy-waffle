//
// Created by wysockipatryk on 12/26/16.
//

#include <SDL.h>
#include <SDL_image.h>
#include <LuaBridge/LuaBridge.h>
#include "Game.h"

using namespace luabridge;

Game * Game::gameSingleton = nullptr;

void Game::UpdateInput() {
	inputManager->UpdateInputs();
}

Game::Game() : isFinished(false) {

}
void Game::Prepare() {
	if(!init()) {
		printf("[err]cant initialize SDL \n");
	} else {
		printf("[suc]SDL initialized \n");
	}
	SDL_Surface * surface = SDL_GetWindowSurface(mainWindow);
	if(surface == NULL) {
		printf("[err]ERROR: %s \n", SDL_GetError());
	}
	mainSurface = surface;
	textureManager = new TextureManager();
	inputManager = new InputManager();
}

Game::~Game() {
	delete textureManager;
	delete inputManager;
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
	SDL_RenderClear(mainRenderer);
	for(auto itr = renders.begin(); itr != renders.end(); itr++) {
		IRenderable * renderable = *itr;
		renderable->Render(mainRenderer);
	}
	SDL_RenderPresent(mainRenderer);
}

void Game::Setup() {
	gameSingleton = new Game();
	gameSingleton->Prepare();
}

void Game::Close() {
	delete gameSingleton;
}

Game *Game::GetGame() {
	return gameSingleton;
}

TextureManager * Game::GetTextureManager() const {
	return textureManager;
}

SDL_Window * Game::GetWindow() const {
	return mainWindow;
}

SDL_Renderer * Game::GetRenderer() const {
	return mainRenderer;
}

SDL_Surface * Game::GetSurface() const {
	return mainSurface;
}

void Game::SubscribeActor(Actor *actor) {
	actors.insert(actor);
}

void Game::SubscribeTick(ITickable *tick) {
	ticks.insert(tick);
}

void Game::SubscribeRender(IRenderable *render) {
	renders.insert(render);
}

void Game::setupLuaState() {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	prepareSingletonsForLua(L);
}

void Game::prepareSingletonsForLua(lua_State *L) {
	using namespace luabridge;
	inputManager->LuaExport(L);
	getGlobalNamespace(L)
		.beginClass<Game>("Game")
			.addFunction("GetInputManager", &Game::GetInputManager)
		.endClass();
}

InputManager *Game::GetInputManager() const {
	return nullptr;
}
