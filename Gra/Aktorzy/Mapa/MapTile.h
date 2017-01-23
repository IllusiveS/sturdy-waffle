//
// Created by wysockipatryk on 1/2/17.
//

#ifndef SDLPODSTAWA_EXE_MAPTILE_H
#define SDLPODSTAWA_EXE_MAPTILE_H


#include <Gra/Tekstury/Texture.h>
#include <Gra/Aktorzy/IRenderable.h>

class MapTile : private IRenderable {
public:
	MapTile();
	void SetupTexture(int x, int y, Texture * texture);
private:
	int x, y;
	Texture * texture;
	virtual void Render(SDL_Renderer * renderer);
};


#endif //SDLPODSTAWA_EXE_MAPTILE_H
