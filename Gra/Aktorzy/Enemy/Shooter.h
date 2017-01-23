//
// Created by zengel on 1/23/17.
//

#ifndef SDLPODSTAWA_EXE_SHOOTER_H
#define SDLPODSTAWA_EXE_SHOOTER_H


#include <Gra/Game.h>
#include "Enemy.h"

class Shooter : Enemy {
public:
    Shooter(Vector2 position) : Enemy(position) {
        speedX = -100;
        speedY = 0;
        tex = Game::GetGame()->GetTextureManager()->GetTexture("shooter");
        type = "Enemy";

    }

    void Tick(float delta) override;
private:
    bool moving = false;
    float destinationY;
    long old;
    int hp = 3;

    void collide(IPhysicsable *coll) override;
};


#endif //SDLPODSTAWA_EXE_SHOOTER_H
