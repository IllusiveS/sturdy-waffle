//
// Created by zengel on 1/22/17.
//

#include <iostream>
#include "Strafer.h"

void Strafer::Tick(float delta) {
    if (position.y >= startingPosition.y + 150) {
        speedY = -200;
        Fire();
    }

    if (position.y <= startingPosition.y - 150) {
        speedY = 200;
        Fire();
    }
    if (position.y == startingPosition.y) {
        Fire();
    }

    Move(Vector2(speedX * delta, speedY * delta));


}