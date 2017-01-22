//
// Created by wysockipatryk on 1/20/17.
//

#include <iostream>
#include <Gra/Game.h>
#include "TestCollider.h"
#include <Gra/Aktorzy/IPhysicsable.h>
#include <Gra/Aktorzy/Actor.h>
#include <Gra/Aktorzy/IRenderable.h>

void TestCollider::collide(IPhysicsable *coll) {
}

TestCollider::TestCollider() : IPhysicsable() {
	position = Vector2(300, 300);
	aabb = AABB(Vector2(0, 0), Vector2(32, 32));
	tex = Game::GetGame()->GetTextureManager()->GetTexture("player");
}

void TestCollider::Render(SDL_Renderer *renderer) {
	tex->render(position.x, position.y);
}


