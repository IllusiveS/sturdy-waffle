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
#include "Gra/Tekstury/TextureManager.h"
#include "InputManager.h"

class Game {
public:
	static void Setup();
	void Prepare();
	static void Close();
	bool isFinished;
	void UpdateInput();
	void UpdateTick();
	void UpdatePhysics();
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
	void SubscribeRender(IRenderable * render);

private:
	bool init();

	void prepareSingletonsForLua(lua_State * L);

	std::set<ITickable *> ticks;
	std::set<IRenderable *> renders;
	std::set<Actor *> actors;

	SDL_Window * mainWindow;
	SDL_Surface * mainSurface;
	SDL_Renderer * mainRenderer;
	TextureManager * textureManager;
	InputManager * inputManager;
	//TODO GameManager
};


#endif //SDLPODSTAWA_GRA_H
