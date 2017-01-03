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
	if(texturesArray.isNil()) {
		printf("cant read textures array\n");
	}
	Iterator itr = Iterator(texturesArray);
	for( ; !itr.isNil(); ) {
		std::string texName = itr.key();
		std::string texPath = itr.value();
		Texture * newTexture = new Texture();
		if(newTexture->createTextureFromFile(texPath)) {
			textures.insert ( std::pair<std::string, Texture *>(texName, newTexture) );
			printf("[suc]Created texture for %s \n", texPath.c_str());
		} else {
			printf("[err]Cant generate texture %s \n", texPath.c_str());
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