//
// Created by wysockipatryk on 12/26/16.
//

#include "TextureManager.h"

SDL_Texture * TextureManager::GetTexture(std::string nazwaTextury) const {
	return nullptr;
}

TextureManager::TextureManager() {
	textures = std::map<std::string, SDL_Texture *>();
	//lua_State *state = luaL_newstate();
}

TextureManager::~TextureManager() {

}
