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
	//TODO wskaźniki do aktorów gry
	//TODO wskaźniki do funkcji (renderingu i updejtu)
	SDL_Window * mainWindow;
	TextureManager * textureManager;
	SDL_Renderer * mainRenderer;
	//TODO GameManager
	//TODO statyczny dostęp mnie się wydaje do klasy
};


#endif //SDLPODSTAWA_GRA_H
