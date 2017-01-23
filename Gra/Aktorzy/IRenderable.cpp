//
// Created by wysockipatryk on 12/26/16.
//

#include <Gra/Game.h>
#include "IRenderable.h"

IRenderable::IRenderable() {
	Game::GetGame()->SubscribeRender(this);
}

IRenderable::~IRenderable() {
	Game::GetGame()->UnSubscribeRender(this);
}
