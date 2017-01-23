//
// Created by zengel on 1/22/17.
//

#include "PlayerProjectile.h"

void PlayerProjectile::Tick(float delta) {
    if (position.x >= 800) {
        Destroy();
    }
    Move(Vector2(speedX * delta, speedY*delta));
}