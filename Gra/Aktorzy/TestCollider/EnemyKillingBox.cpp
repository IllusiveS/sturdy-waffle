//
// Created by wysockipatryk on 1/23/17.
//

#include "EnemyKillingBox.h"

EnemyKillingBox::EnemyKillingBox() : Actor(), IPhysicsable() {
	type = "EnemyKillingBox";
	position = Vector2(-250, 400);
	aabb = AABB(Vector2(-250, 400), Vector2(50, 9001));
}

EnemyKillingBox::~EnemyKillingBox() {

}

void EnemyKillingBox::collide(IPhysicsable *coll) {

}
