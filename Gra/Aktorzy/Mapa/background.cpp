//
// Created by piorunes on 23.01.17.
//

#include <Gra/Game.h>
#include "background.h"

background::background() : IRenderable(), ITickable() {
    texture = Game::GetGame()->GetTextureManager()->GetTexture("bg");
    bgRect.x=0;
    bgRect.y=0;
    layer=0;
}

void background::Render(SDL_Renderer * renderer) {
    texture->render(400, 300, 800, 600, bgRect);
}


void background::Tick(float delta) {
    if (bgRect.x >=800){bgRect.x = 0;}
    bgRect.x = bgRect.x +1;


}