//
// Created by wysockipatryk on 1/7/17.
//

#include <Gra/Game.h>
#include "IPhysicsable.h"

IPhysicsable::IPhysicsable() : aabb(Vector2(0, 0), Vector2(16, 16)){
	Game::GetGame()->SubscribePhysics(this);
}

IPhysicsable::~IPhysicsable() {
	Game::GetGame()->UnSubscribePhysics(this);
}

void IPhysicsable::CalculatePhysics(float delta) {
	oldPosition = position;
	oldSpeed = speedVector;
	position = position.add(speedVector);
	aabb.center = position;
}

SweepData IPhysicsable::getBeginSweepData() {
	return SweepData(this, aabb.center.x - aabb.halfSize.x, true);
}

SweepData IPhysicsable::getEndSweepData() {
	return SweepData(this, aabb.center.x + aabb.halfSize.x, false);
}

bool IPhysicsable::checkCollision(IPhysicsable * other) {
	return aabb.Overlaps(other->aabb);
}

