//
// Created by wysockipatryk on 12/26/16.
//

#include <SDL.h>
#include <SDL_image.h>
#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include <Gra/Matma/Vector2.h>
#include <Gra/Aktorzy/Player/Player.h>
#include <Gra/Aktorzy/TestCollider/TestCollider.h>
#include <Gra/Aktorzy/Collisions/CollisionManager.h>
#include "Game.h"

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
	collisionManager = new CollisionManager();
	setupLuaState();
	Player * player = new Player();
	player->ReadScript(L);
	TestCollider * coll = new TestCollider();
}

Game::~Game() {
	delete textureManager;
	delete inputManager;
	for(auto itr = actors.begin(); itr != actors.end(); itr++) {
		Actor * actor = *itr;
		delete actor;
	}
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

void Game::UpdateTick(float delta) {
	for(auto itr = ticks.begin(); itr != ticks.end(); itr++) {
		ITickable * tickable = *itr;
		tickable->Tick(delta);
	}
}

void Game::UpdatePhysics(float delta) {
	collisionManager->processPhysics(delta);
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
	this->L = L;
	luaL_openlibs(L);
	prepareClassesForLua(L);
}

void Game::prepareClassesForLua(lua_State *L) {
	using namespace luabridge;
	inputManager->ExportLua(L);
	Vector2::ExportLua(L);
	Player::ExportLua(L);
	ExportLua(L);
}

void Game::ExportLua(lua_State *L) {
	using namespace luabridge;
	getGlobalNamespace(L)
			.beginClass<Game>("Game")
			.addStaticFunction ("getGame", &Game::GetGame)
			.addFunction("getInputManager", &Game::GetInputManager)
			.endClass();
}

InputManager *Game::GetInputManager() const {
	return inputManager;
}

void Game::SubscribePhysics(IPhysicsable * phi) {
	collisionManager->subscribePhysicable(phi);
}

void Game::UnSubscribeActor(Actor *actor) {
	actorsToBeRemoved.insert(actor);
}

void Game::UnSubscribeTick(ITickable *tick) {
	ticks.erase(tick);
}

void Game::UnSubscribePhysics(IPhysicsable *phi) {
	collisionManager->unSubscribePhysicable(phi);
}

void Game::UnSubscribeRender(IRenderable *render) {
	renders.erase(render);
}

void Game::RemoveActors() {
	for(auto itr = actorsToBeRemoved.begin(); itr != actorsToBeRemoved.end(); itr++) {
		Actor * actorToRemove = *itr;
		actors.erase(actorToRemove);
		delete actorToRemove;
	}
	actorsToBeRemoved.clear();
}
