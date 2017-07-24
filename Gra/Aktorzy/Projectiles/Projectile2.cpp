//
// Created by zengel on 1/24/17.
//

#include <Gra/Matma/Vector2.h>
#include "Projectile2.h"


void Projectile2::Tick(float delta) {
    if (duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()).count() - old > 600) {

        Projectile1 * proj1 = new Projectile1(Vector2(position.x, position.y));
        Projectile1 * proj2 = new Projectile1(Vector2(position.x, position.y));

        proj1->speedY = 200;
        proj2->speedY = -200;
        old = duration_cast<milliseconds>(
                system_clock::now().time_since_epoch()).count();
    }

    Move(Vector2(tarDir.x * delta * speedX, tarDir.y * delta * speedY));
}