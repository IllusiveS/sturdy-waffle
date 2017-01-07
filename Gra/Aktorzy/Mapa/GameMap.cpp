//
// Created by wysockipatryk on 1/2/17.
//

#include <lua.hpp>
#include <Gra/Game.h>
#include "LuaBridge/LuaBridge.h"
#include "GameMap.h"

using namespace luabridge;

void GameMap::ReadMapFromFile(std::string path) {
	lua_State *L = luaL_newstate();
	luaL_dofile(L, path.c_str());
	luaL_openlibs(L);
	lua_pcall(L, 0, 0, 0);
	LuaRef tilesTypes = getGlobal(L, "maptiles");
	LuaRef map = getGlobal(L, "map");
	Iterator itr = Iterator(map);
	for( int x = 0; !itr.isNil(); x++) {
		LuaRef value = itr.value();
		Iterator rowItr = Iterator(value);
		for(int y = 0; !rowItr.isNil(); y++) {
			if (rowItr.value().isString()) {
				std::string tileTypeString = rowItr.value();
				LuaRef type = tilesTypes[tileTypeString];
				std::string name = type["name"];
				std::string texture = type["texture"];
				MapTile * newTile = new MapTile();
				Texture * foundTexture = Game::GetGame()->GetTextureManager()->GetTexture(texture);
				newTile->SetupTexture(y * 32, x * 32, foundTexture);
				mapElements.insert(newTile);
			}
			++rowItr;
		}
		++itr;
	}
}

GameMap::GameMap() : Actor() {

}
