//
// Created by zengel on 1/22/17.
//

#ifndef SDLPODSTAWA_EXE_ENEMYB_H
#define SDLPODSTAWA_EXE_ENEMYB_H


#include <Gra/Game.h>
#include "Enemy.h"

class Charger : Enemy {
public:
    Charger(Vector2 position) : Enemy(position) {
        speedX = -75;
        speedY = 0;
        tex = Game::GetGame()->GetTextureManager()->GetTexture("charger");

    }

    void Tick(float delta) override;
};


#endif //SDLPODSTAWA_EXE_ENEMYB_H
