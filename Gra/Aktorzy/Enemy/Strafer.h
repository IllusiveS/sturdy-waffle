//
// Created by zengel on 1/22/17.
//

#ifndef SDLPODSTAWA_EXE_ENEMYA_H
#define SDLPODSTAWA_EXE_ENEMYA_H


#include <Gra/Game.h>
#include "Enemy.h"

class Strafer : Enemy {
public:
    Strafer(Vector2 position) : Enemy(position) {
        speedX = -50;
        speedY = 200;
        tex = Game::GetGame()->GetTextureManager()->GetTexture("strafer");
        type = "Enemy";

    }

    void Tick(float delta) override;
};


#endif //SDLPODSTAWA_EXE_ENEMYA_H
