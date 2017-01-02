//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_GRA_H
#define SDLPODSTAWA_GRA_H

//Klasa do zarządzania całą grą

#include "Gra/Tekstury/TextureManager.h"

class Game {
public:
	static void Setup();
	void Prepare();
	static void Close();

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

private:
	bool init();
	//TODO wskaźniki do aktorów gry
	//TODO wskaźniki do funkcji (renderingu i updejtu)
	SDL_Window * mainWindow;
	SDL_Surface * mainSurface;
	SDL_Renderer * mainRenderer;
	TextureManager * textureManager;
	//TODO GameManager
	//TODO statyczny dostęp mnie się wydaje do klasy
};


#endif //SDLPODSTAWA_GRA_H
