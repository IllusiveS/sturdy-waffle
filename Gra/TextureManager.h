//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_TEXTUREMANAGER_H
#define SDLPODSTAWA_TEXTUREMANAGER_H

#include <string>
#include <map>
#include <SDL_render.h>

//#include <LuaBridge.h>
#include <iostream>

extern "C" {
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}

//Klasa do przechowywania tekstur
class TextureManager {
public:
	TextureManager(SDL_Renderer * renderer);
	~TextureManager();

	SDL_Texture * GetTexture(std::string nazwaTextury) const;
private:
	std::map<std::string, SDL_Texture *> textures;
	SDL_Renderer * mainRenderer;
	SDL_Window * window;

	void ReadTextures();
};


#endif //SDLPODSTAWA_TEXTUREMANAGER_H
