//
// Created by zengel on 1/22/17.
//

#ifndef SDLPODSTAWA_EXE_ENEMYMANAGER_H
#define SDLPODSTAWA_EXE_ENEMYMANAGER_H


#include <set>
#include "Enemy.h"
#include <chrono>
#include <map>
#include <functional>

class EnemyManager;

typedef std::function<void(EnemyManager*, Vector2)> CreateFunc;

using namespace std::chrono;

class EnemyManager: ITickable {
public:
    long startTime = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()).count();
	long waitTime = 1000;
    void spawnWaves();
    std::set<Enemy *> enemies;

    void spawnWave();

    bool wave1 = false;
    bool wave2 = false;
    bool wave3 = false;
    bool wave4 = false;
    bool wave5 = false;
    bool wave6 = false;
    bool wave7 = false;
    bool finalWave = false;

    void Tick(float delta) override;

	void ReadScript(lua_State * L);
	static void ExportLua(lua_State *L);
public:
	void SpawnEnemy(Vector2 pos, std::string type);

	void CreateCharger(Vector2 pos);
	void CreateShooter(Vector2 pos);
	void CreateStraferUp(Vector2 pos);
	void CreateStraferDown(Vector2 pos);
	void CreateAsteroid(Vector2 pos);
	void CreateBoss(Vector2 pos);

	std::map<std::string, CreateFunc> spawners;
	void SetupSpawners();
	std::shared_ptr<luabridge::LuaRef> spawnFunc;

	void SetWaitTime(long time);

	long GetWaitTime() const;
};


#endif //SDLPODSTAWA_EXE_ENEMYMANAGER_H
