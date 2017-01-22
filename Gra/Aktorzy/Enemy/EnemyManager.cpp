//
// Created by zengel on 1/22/17.
//

#include <Gra/Matma/Vector2.h>
#include "EnemyManager.h"
#include "Enemy.h"
#include "Strafer.h"
#include "Charger.h"

void EnemyManager::spawnEnemy() {
    EnemyA * enemyA = new EnemyA(Vector2(400,200));
    EnemyB * enemyB = new EnemyB(Vector2(400,400));

}

