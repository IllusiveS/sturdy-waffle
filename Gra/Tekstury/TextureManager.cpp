//
// Created by wysockipatryk on 12/26/16.
//

#include "TextureManager.h"
#include <iostream>
#include <SDL_image.h>
#include "LuaBridge/LuaBridge.h"

using namespace luabridge;

Texture * TextureManager::GetTexture(std::string nazwaTextury) const {
	Texture * texToReturn = textures.at(nazwaTextury);
	return texToReturn;
}

TextureManager::TextureManager() {
	ReadTextures();
}

void TextureManager::ReadTextures() {
	textures = std::map<std::string, Texture *>();
	lua_State *L = luaL_newstate();
	luaL_dofile(L, "Lua/Textures.lua");
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
	std::cout << "ReadingTextures" << std::endl;
	LuaRef texturesArray = getGlobal(L, "textures");
	Iterator itr = Iterator(texturesArray);
	for( ; !itr.isNil(); ) {
		std::string texName = itr.key();
		std::string texPath = itr.value();
		Texture * newTexture = new Texture();
		if(newTexture->createTextureFromFile(texPath)) {
			textures[texName] = newTexture;
		} else {
			delete newTexture;
		}
		++itr;
	}
}

TextureManager::~TextureManager() {
	for(auto itr = textures.begin(); itr != textures.end(); itr++) {
		itr->second->free();
	}
}