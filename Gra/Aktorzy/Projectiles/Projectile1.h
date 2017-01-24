//
// Created by zengel on 1/22/17.
//

#ifndef SDLPODSTAWA_EXE_PROJECTILE1_H
#define SDLPODSTAWA_EXE_PROJECTILE1_H

#include <Gra/Game.h>
#include "Projectile1.h"
#include "Projectile.h"

class Projectile1 : public Projectile {
public:
    Projectile1(Vector2 position) : Projectile(position) {
        speedX = -225;
        speedY = 0;
        tex = Game::GetGame()->GetTextureManager()->GetTexture("projectile1");
        type = "Projectile1";
    }

    void Tick(float delta) override;
};

#endif //SDLPODSTAWA_EXE_PROJECTILE1_H
