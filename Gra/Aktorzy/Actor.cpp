//
// Created by wysockipatryk on 12/26/16.
//

#include <Gra/Game.h>
#include "Actor.h"

Actor::Actor() {
	Game::GetGame()->SubscribeActor(this);
}


void Actor::Destroy() {
    Game::GetGame()->UnSubscribeActor(this);
}

Actor::~Actor() {


}
