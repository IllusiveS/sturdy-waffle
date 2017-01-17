//
// Created by wysockipatryk on 1/7/17.
//

#include <Gra/Game.h>
#include "IPhysicsable.h"

IPhysicsable::IPhysicsable() : aabb(Vector2(), Vector2()){
	Game::GetGame()->SubscribePhysics(this);
}

IPhysicsable::~IPhysicsable() {

}

void IPhysicsable::CalculatePhysics(float delta) {
	oldPosition = position;
	oldSpeed = speedVector;
	position = position.add(speedVector);
}
