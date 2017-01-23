//
// Created by zengel on 1/23/17.
//

#include <Gra/Aktorzy/Projectiles/PlayerProjectile.h>
#include <Gra/Aktorzy/Projectiles/Projectile1.h>
#include "Asteroid.h"

void Asteroid::Tick(float delta) {
    Move(Vector2(speedX * delta, speedY*delta));
}

void Asteroid::collide(IPhysicsable *coll) {
    if (!coll->type.compare("PlayerProjectile")) {
        ((PlayerProjectile *) coll)->Destroy();
    }

    if (!coll->type.compare("Projectile1")) {
        ((Projectile1 *) coll)->Destroy();
    }
}