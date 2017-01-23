//
// Created by zengel on 1/23/17.
//

#include "Shooter.h"
#include <Gra/Game.h>
#include <chrono>
#include <Gra/Aktorzy/Projectiles/PlayerProjectile.h>

using namespace std::chrono;

void Shooter::collide(IPhysicsable *coll) {
    if (!coll->type.compare("PlayerProjectile")) {
        ((PlayerProjectile *) coll)->Destroy();
        hp--;
        if(hp==2) {
            tex = Game::GetGame()->GetTextureManager()->GetTexture("shooter_damaged1");

        } else if (hp==1) {
            tex = Game::GetGame()->GetTextureManager()->GetTexture("shooter_damaged2");

        } else {
            Destroy();
        }
    }
}

void Shooter::Tick(float delta) {

    if (position.x <= 700) {
        speedX = 0;


        destinationY = Game::GetGame()->GetPlayer()->position.y;
        if (destinationY < position.y) {
            speedY = -150;
        } else {
            speedY = 150;
        }

        if (abs(destinationY - position.y) < 40) {
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