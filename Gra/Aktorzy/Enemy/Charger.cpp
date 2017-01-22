//
// Created by zengel on 1/22/17.
//

#include <Gra/Matma/Vector2.h>
#include "Charger.h"

void EnemyB::Tick(float delta) {
    speedX-= 1;
    Move(Vector2(speedX * delta, speedY*delta));
}