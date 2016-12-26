//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_GRA_H
#define SDLPODSTAWA_GRA_H

//Klasa do zarządzania całą grą

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
	//TODO Texture manager
	//TODO GameManager
	//TODO statyczny dostęp mnie się wydaje do klasy
};


#endif //SDLPODSTAWA_GRA_H
