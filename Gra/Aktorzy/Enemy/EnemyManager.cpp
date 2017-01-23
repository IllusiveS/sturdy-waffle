//
// Created by zengel on 1/22/17.
//

#include <Gra/Matma/Vector2.h>
#include "EnemyManager.h"
#include "Enemy.h"
#include "Strafer.h"
#include "Charger.h"
#include "Shooter.h"

void EnemyManager::spawnEnemy() {
    Strafer * enemyA = new Strafer(Vector2(800,200));
    Charger * enemyB = new Charger(Vector2(800,400));
    Shooter * enemyC = new Shooter(Vector2(800,300));
}

