//
// Created by zengel on 1/22/17.
//

#ifndef SDLPODSTAWA_EXE_PLAYERPROJECTILE_H
#define SDLPODSTAWA_EXE_PLAYERPROJECTILE_H


#include <Gra/Game.h>
#include "Projectile.h"

class PlayerProjectile : Projectile {
public:
    PlayerProjectile(Vector2 position) : Projectile(position) {
        speedX = 300;
        speedY = 0;
        tex = Game::GetGame()->GetTextureManager()->GetTexture("playerProjectile");
        type="PlayerProjectile";
    }

    void Tick(float delta) override;
};


#endif //SDLPODSTAWA_EXE_PLAYERPROJECTILE_H
