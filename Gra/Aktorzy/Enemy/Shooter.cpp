//
// Created by zengel on 1/23/17.
//

#include "Shooter.h"
#include <Gra/Game.h>
#include <chrono>

using namespace std::chrono;

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
                    system_clock::now().time_since_epoch()).count() - old > 400) {
                Fire();
                moving = false;
                old = duration_cast<milliseconds>(
                        system_clock::now().time_since_epoch()).count();
            }
        }
    }



std::cout << position.y <<
std::endl;
std::cout << destinationY <<
std::endl;


Move (Vector2(speedX *delta, speedY *delta));


}