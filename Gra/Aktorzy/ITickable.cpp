//
// Created by wysockipatryk on 12/26/16.
//

#include <Gra/Game.h>
#include <Gra/Aktorzy/Enemy/EnemyManager.h>
#include "ITickable.h"

ITickable::ITickable() {
	Game::GetGame()->SubscribeTick(this);
}

void ITickable::Tick(float delta) {
for (auto &enemy : EnemyManager::enemies) {
	enemy->Move(Vector2(-1,0));
}
}
