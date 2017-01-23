//
// Created by zengel on 1/22/17.
//

#include "Projectile1.h"

void Projectile1::Tick(float delta) {
    Move(Vector2(speedX * delta, speedY*delta));
}
