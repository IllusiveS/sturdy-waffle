//
// Created by zengel on 1/24/17.
//

#ifndef SDLPODSTAWA_EXE_PROJECTILE2_H
#define SDLPODSTAWA_EXE_PROJECTILE2_H

#include <Gra/Game.h>
#include "Projectile1.h"
#include "Projectile.h"

class Projectile2 : public Projectile {
public:
    Projectile2(Vector2 position) : Projectile(position) {
        speedX = -300;
        speedY = 0;
        tex = Game::GetGame()->GetTextureManager()->GetTexture("projectile2");
        type = "Projectile2";
    }
    bool moving = false;
    float destinationY;
    long old;
    void Tick(float delta) override;
};

#endif //SDLPODSTAWA_EXE_PROJECTILE2_H
