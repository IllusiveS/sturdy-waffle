//
// Created by zengel on 1/23/17.
//

#ifndef SDLPODSTAWA_EXE_ASTEROID_H
#define SDLPODSTAWA_EXE_ASTEROID_H

#include <Gra/Game.h>
#include "Enemy.h"

class Asteroid : Enemy {
public:
    Asteroid(Vector2 position) : Enemy(position) {
        speedX = -175;
        speedY = 0;
        tex = Game::GetGame()->GetTextureManager()->GetTexture("asteroid");
        type = "Asteroid";
	    aabb = AABB(Vector2(), Vector2(48, 48));
    }

    void Tick(float delta) override;

    void collide(IPhysicsable *coll) override;
};


#endif //SDLPODSTAWA_EXE_ASTEROID_H
