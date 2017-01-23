//
// Created by zengel on 1/22/17.
//

#include <iostream>
#include <Gra/Aktorzy/Projectiles/Projectile1.h>
#include "Strafer.h"

void Strafer::Tick(float delta) {
    destinationX = Game::GetGame()->GetPlayer()->position.x;
    destinationY = Game::GetGame()->GetPlayer()->position.y;
    if (position.y >= startingPosition.y + 75) {
        speedY = -300;
    }

    if (position.y <= startingPosition.y - 75) {
        speedY = 300;

    }

    if (abs(destinationX - position.x) < 20) {
        if (duration_cast<milliseconds>(
                system_clock::now().time_since_epoch()).count() - old > 600) {
            Projectile1 *proj = new Projectile1(Vector2(position.x, position.y));
            proj->speedX = 0;
            if (destinationY < position.y) {
                proj->speedY = -200;
            } else {
                proj->speedY = 200;
            }
            old = duration_cast<milliseconds>(
                    system_clock::now().time_since_epoch()).count();
        }
    }


    Move(Vector2(speedX * delta, speedY * delta));


}