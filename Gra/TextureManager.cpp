//
// Created by wysockipatryk on 12/26/16.
//

#include "TextureManager.h"
#include <iostream>
#include <SDL_image.h>
#include "LuaBridge/LuaBridge.h"

using namespace luabridge;

SDL_Texture * TextureManager::GetTexture(std::string nazwaTextury) const {
	return nullptr;
}

TextureManager::TextureManager(SDL_Renderer * renderer, SDL_Surface * mainSurface) : mainRenderer(renderer), mainSurface(mainSurface) {
	ReadTextures();
}

void TextureManager::ReadTextures() {
	textures = std::map<std::string, SDL_Texture *>();
	lua_State *L = luaL_newstate();
	luaL_dofile(L, "Lua/Textures.lua");
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
	std::cout << "ReadingTextures" << std::endl;
	LuaRef texturesArray = getGlobal(L, "textures");
	Iterator itr = Iterator(texturesArray);
	int length = texturesArray.length();
	for( ; !itr.isNil(); ) {
		std::string texName = itr.key();
		std::string texPath = itr.value();
		SDL_Surface * loadedSurface = loadSurface(texPath);
		if(loadedSurface == NULL){
			printf("[err]failed to load texture %s from %s ERROR: %s \n", texName.c_str(), texPath.c_str(), SDL_GetError());
		} else {
			SDL_Texture * newTex = SDL_CreateTextureFromSurface(mainRenderer, loadedSurface);
			if(newTex == NULL) {
				printf("[err]failed to create texture %s ERROR: %s \n", texName.c_str(), SDL_GetError());
			} else {
				printf("[suc]created texture %s from %s \n", texName.c_str(), texPath.c_str());
				SDL_FreeSurface(loadedSurface);
				textures[texName] = newTex;
			}
		}
		++itr;
	}
}

SDL_Surface* TextureManager::loadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "[err]Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, mainSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "[err]Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

TextureManager::~TextureManager() {
	for(auto itr = textures.begin(); itr != textures.end(); itr++) {
		SDL_DestroyTexture(itr->second);
	}
}