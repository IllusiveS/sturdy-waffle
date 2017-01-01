//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_GRA_H
#define SDLPODSTAWA_GRA_H

//Klasa do zarządzania całą grą

#include "TextureManager.h"

class Game {
public:
	Game();
	~Game();

	void UpdateInput();
	void UpdateTick();
	void UpdatePhysics();
	void Render();
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
