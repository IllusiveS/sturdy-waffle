//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_TEXTUREMANAGER_H
#define SDLPODSTAWA_TEXTUREMANAGER_H

#include <string>
#include <map>
#include <SDL_render.h>

#include <iostream>
#include "Texture.h"

//Klasa do przechowywania tekstur
class TextureManager {
public:
	TextureManager();
	~TextureManager();

	Texture * GetTexture(std::string nazwaTextury) const;
private:
	std::map<std::string, Texture *> textures;

	void ReadTextures();
};


#endif //SDLPODSTAWA_TEXTUREMANAGER_H
