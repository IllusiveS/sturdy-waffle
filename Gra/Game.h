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
#include <Gra/Aktorzy/IPhisicsable.h>
#include "Gra/Tekstury/TextureManager.h"
#include "InputManager.h"

class Game {
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
	void SubscribePhysics(IPhisicsable * phi);
	void SubscribeRender(IRenderable * render);

	void UnSubscribeActor(Actor * actor);
	void UnSubscribeTick(ITickable * tick);
	void UnSubscribePhysics(IPhisicsable * phi);
	void UnSubscribeRender(IRenderable * render);

private:
	bool init();
	lua_State * L;
	void prepareClassesForLua(lua_State *L);

	std::set<ITickable *> ticks;
	std::set<IRenderable *> renders;
	std::set<IPhisicsable *> physics;
	std::set<Actor *> actors;

	SDL_Window * mainWindow;
	SDL_Surface * mainSurface;
	SDL_Renderer * mainRenderer;
	TextureManager * textureManager;
	InputManager * inputManager;
	//TODO GameManager
	void ExportLua(lua_State *L);
};


#endif //SDLPODSTAWA_GRA_H
