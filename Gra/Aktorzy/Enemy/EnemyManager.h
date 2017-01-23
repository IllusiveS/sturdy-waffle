//
// Created by zengel on 1/22/17.
//

#ifndef SDLPODSTAWA_EXE_ENEMYMANAGER_H
#define SDLPODSTAWA_EXE_ENEMYMANAGER_H


#include <set>
#include "Enemy.h"
#include <chrono>

using namespace std::chrono;

class EnemyManager: ITickable {
public:
    long startTime = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()).count();
    void spawnWaves();
    std::set<Enemy *> enemies;

    void spawnWave1();
    void spawnWave2();
    void spawnWave3();
    void spawnWave4();
    void spawnWave5();

    bool wave1 = false;
    bool wave2 = false;
    bool wave3 = false;
    bool wave4 = false;
    bool wave5 = false;
    bool wave6 = false;
    bool wave7 = false;

    void Tick(float delta) override;

    void spawnWave6();
};


#endif //SDLPODSTAWA_EXE_ENEMYMANAGER_H
