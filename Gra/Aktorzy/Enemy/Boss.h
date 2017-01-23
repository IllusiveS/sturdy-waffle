//
// Created by zengel on 1/24/17.
//

#ifndef SDLPODSTAWA_EXE_BOSS_H
#define SDLPODSTAWA_EXE_BOSS_H


#include <Gra/Game.h>
#include "Enemy.h"

class Boss : Enemy {
public:
    Boss(Vector2 position) : Enemy(position) {
        speedX = -100;
        speedY = 0;
        tex = Game::GetGame()->GetTextureManager()->GetTexture("boss");
        type = "Enemy";
        aabb = AABB(Vector2(0, 0), Vector2(64, 64));

    }
    int hp = 20;
    bool moving = false;
    float destinationY;
    long old;
    long old2;
    void Tick(float delta) override;
    void collide(IPhysicsable *coll) override;

    void SuperFire();
};


#endif //SDLPODSTAWA_EXE_BOSS_H
