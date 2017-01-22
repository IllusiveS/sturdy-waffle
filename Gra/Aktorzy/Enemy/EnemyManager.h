//
// Created by zengel on 1/22/17.
//

#ifndef SDLPODSTAWA_EXE_ENEMYMANAGER_H
#define SDLPODSTAWA_EXE_ENEMYMANAGER_H


#include <set>
#include "Enemy.h"

class EnemyManager {
public:

    void spawnEnemy();
    std::set<Enemy *> enemies;
};


#endif //SDLPODSTAWA_EXE_ENEMYMANAGER_H
