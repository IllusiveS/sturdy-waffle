//
// Created by zengel on 1/24/17.
//

#include <Gra/Aktorzy/Projectiles/PlayerProjectile.h>
#include <Gra/Aktorzy/Projectiles/Projectile1.h>
#include <Gra/Aktorzy/Projectiles/Projectile2.h>
#include "Boss.h"

void Boss::collide(IPhysicsable *coll) {
    if (!coll->type.compare("PlayerProjectile")) {
        ((PlayerProjectile *) coll)->Destroy();
        hp--;

        if (hp <= 0) {
            Destroy();
        }

    }

}

void Boss::Tick(float delta) {
    if (duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()).count() - old2 > 200)
    tex = Game::GetGame()->GetTextureManager()->GetTexture("boss");

    if (position.x <= 750) {
        speedX = 0;
        destinationY = Game::GetGame()->GetPlayer()->position.y;
        if (destinationY < position.y) {
            speedY = -150;
        } else {
            speedY = 150;
        }

        if (abs(destinationY - position.y) < 20) {
            if (duration_cast<milliseconds>(
                    system_clock::now().time_since_epoch()).count() - old2 > 1200) {
                tex = Game::GetGame()->GetTextureManager()->GetTexture("boss2");

                SuperFire();
                moving = false;
                old2 = duration_cast<milliseconds>(
                        system_clock::now().time_since_epoch()).count();

            } else
            if (duration_cast<milliseconds>(
                    system_clock::now().time_since_epoch()).count() - old > 600) {
                Fire();
                moving = false;
                old = duration_cast<milliseconds>(
                        system_clock::now().time_since_epoch()).count();
            }

        }


    }

    Move(Vector2(speedX * delta, speedY * delta));
}

void Boss::SuperFire() {
    Projectile2 *proj = new Projectile2(Vector2(position.x - 34, position.y));
}