//
// Created by zengel on 1/22/17.
//

#include <Gra/Matma/Vector2.h>
#include "EnemyManager.h"
#include "Enemy.h"

EnemyManager::EnemyManager();

void EnemyManager::spawnEnemy() {
    Enemy * enemy = new Enemy(Vector2(600,200));
    enemies.insert(enemy);
}

