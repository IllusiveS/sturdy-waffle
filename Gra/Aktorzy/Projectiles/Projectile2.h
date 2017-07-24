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
    Projectile2(Vector2 position, float xTar, float yTar) : Projectile(position) {
        speedX = 700;
        speedY = 700;
        tex = Game::GetGame()->GetTextureManager()->GetTexture("projectile2");
        type = "Projectile2";
        layer=2;
	    tarDir = Vector2(xTar - position.x, yTar - position.y).normalized();
    }
    bool moving = false;
    float destinationY;
    float destinationX;
	Vector2 tarDir;
    long old;
    void Tick(float delta) override;
};

#endif //SDLPODSTAWA_EXE_PROJECTILE2_H
