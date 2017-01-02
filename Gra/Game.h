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
	//koniec singletona

	//DOSTĘP DO PÓL
public:
	TextureManager * GetTextureManager() const;
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

	std::set<ITickable *> ticks;
	std::set<IRenderable *> renders;
	std::set<Actor *> actors;

	SDL_Window * mainWindow;
	SDL_Surface * mainSurface;
	SDL_Renderer * mainRenderer;
	TextureManager * textureManager;
	//TODO GameManager
};


#endif //SDLPODSTAWA_GRA_H
