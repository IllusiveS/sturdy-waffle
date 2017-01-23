//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_IRENDERABLE_H
#define SDLPODSTAWA_IRENDERABLE_H


#include <SDL_render.h>

class IRenderable {
public:
	IRenderable();

	virtual void Render(SDL_Renderer * renderer) = 0;
};



#endif //SDLPODSTAWA_IRENDERABLE_H
