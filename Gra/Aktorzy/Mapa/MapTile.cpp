//
// Created by wysockipatryk on 1/2/17.
//

#include "MapTile.h"

MapTile::MapTile() : IRenderable() {

}

void MapTile::Render(SDL_Renderer * renderer) {
	texture->render(x, y);
	layer =0;
}

void MapTile::SetupTexture(int x, int y, Texture * texture) {
	this->x = x;
	this->y = y;
	this->texture = texture;
}
