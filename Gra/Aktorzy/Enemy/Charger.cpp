//
// Created by zengel on 1/22/17.
//

#include <Gra/Matma/Vector2.h>
#include "Charger.h"

void Charger::Tick(float delta) {
    Move(Vector2(speedX * delta, speedY*delta));
}