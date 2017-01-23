//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_GRA_H
#define SDLPODSTAWA_GRA_H

//Klasa do zarządzania całą grą

#include <Gra/Aktorzy/IRenderable.h>
#include <set>
#include <Gra/Aktorzy/Actor.h>
#include <Gra/Aktorzy/ITickable.h>
#include <Gra/Aktorzy/IPhysicsable.h>
#include "Gra/Tekstury/TextureManager.h"
#include "InputManager.h"
#include <Gra/Aktorzy/Enemy/EnemyManager.h>

class CollisionManager;

class Game {
	struct render_sortby_layer{
		bool operator()(IRenderable * x, IRenderable * y){
			return x->layer < y->layer;
		}
	};
public:
	static void Setup();
	void Prepare();
	static void Close();
	bool isFinished;
	void UpdateInput();
	void UpdateTick(float delta);
	void UpdatePhysics(float delta);
	void Render();

	//SINGLETON
public:
	static Game * GetGame();
private:
	static Game * gameSingleton;
	Game();
	~Game();
	void setupLuaState();
	//koniec singletona

	//DOSTĘP DO PÓL
public:
	TextureManager * GetTextureManager() const;
	InputManager * GetInputManager() const;
	SDL_Window * GetWindow() const;
	SDL_Renderer * GetRenderer() const;
	SDL_Surface * GetSurface() const;
	//koniec dostępu do pól

public://Zapisywanie się aktorów
	void SubscribeActor(Actor * actor);
	void SubscribeTick(ITickable * tick);
	void SubscribePhysics(IPhysicsable * phi);
	void SubscribeRender(IRenderable * render);

	void UnSubscribeActor(Actor * actor);
	void UnSubscribeTick(ITickable * tick);
	void UnSubscribePhysics(IPhysicsable * phi);
	void UnSubscribeRender(IRenderable * render);


	int SCREEN_WIDTH = 800;
	int SCREEN_HEIGHT = 600;

	void RemoveUnusedActors();


private:
	bool init();
	lua_State * L;
	void prepareClassesForLua(lua_State *L);

	std::set<ITickable *> ticks;
	std::set<IRenderable *, render_sortby_layer> renders;
	std::set<Actor *> actors;
	std::set<Actor *> actorsToBeRemoved;

	SDL_Window * mainWindow;
	SDL_Surface * mainSurface;
	SDL_Renderer * mainRenderer;
	TextureManager * textureManager;
	InputManager * inputManager;
	CollisionManager * collisionManager;
	EnemyManager * enemyManager;
	//TODO GameManager
	void ExportLua(lua_State *L);

};




#endif //SDLPODSTAWA_GRA_H
