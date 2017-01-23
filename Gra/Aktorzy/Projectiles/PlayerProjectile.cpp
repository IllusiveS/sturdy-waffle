//
// Created by zengel on 1/22/17.
//

#include "PlayerProjectile.h"

void PlayerProjectile::Tick(float delta) {
    Move(Vector2(speedX * delta, speedY*delta));
}