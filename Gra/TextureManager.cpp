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

TextureManager::TextureManager(SDL_Renderer * renderer) {
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
	std::__cxx11::string prevKey = "";
	do {
		std::__cxx11::string texName = itr.key();
		if(texName == prevKey) {
			break;
		}
		std::__cxx11::string texPath = itr.value();
		SDL_Surface * loadedSurface = IMG_Load(texPath.c_str());
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
		prevKey = texName;
		++itr;
	} while(true);
}

TextureManager::~TextureManager() {
	for(auto itr = textures.begin(); itr != textures.end(); itr++) {
		SDL_DestroyTexture(itr->second);
	}
}