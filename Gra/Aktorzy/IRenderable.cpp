//
// Created by wysockipatryk on 12/26/16.
//

#include <Gra/Game.h>
#include "IRenderable.h"

IRenderable::IRenderable() {
	layer = 2;
}

IRenderable::~IRenderable() {
	Game::GetGame()->UnSubscribeRender(this);
}

void IRenderable::AddToLayer() {
	Game::GetGame()->SubscribeRender(this);
}
