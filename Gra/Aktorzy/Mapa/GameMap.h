//
// Created by wysockipatryk on 1/2/17.
//

#ifndef SDLPODSTAWA_EXE_GAMEMAP_H
#define SDLPODSTAWA_EXE_GAMEMAP_H

#include <string>
#include <set>
#include "MapTile.h"

class GameMap : private Actor{
public:
	GameMap();
	void ReadMapFromFile(std::string path);

private:
	std::set<MapTile *> mapElements;
};


#endif //SDLPODSTAWA_EXE_GAMEMAP_H
