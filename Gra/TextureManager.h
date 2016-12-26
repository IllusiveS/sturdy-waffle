//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_TEXTUREMANAGER_H
#define SDLPODSTAWA_TEXTUREMANAGER_H

#include <SDL_render.h>
#include <string>

//Klasa do przechowywania tekstur
class TextureManager {
	SDL_Texture GetTexture(std::string nazwaTextury);

};


#endif //SDLPODSTAWA_TEXTUREMANAGER_H
