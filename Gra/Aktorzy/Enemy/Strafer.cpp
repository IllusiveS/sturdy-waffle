//
// Created by zengel on 1/22/17.
//

#include <iostream>
#include "Strafer.h"

void Strafer::Tick(float delta) {
    if (position.y >= startingPosition.y + 75) {
        speedY = -300;
    }

    if (position.y <= startingPosition.y - 75) {
        speedY = 300;

    }


    Move(Vector2(speedX * delta, speedY * delta));


}