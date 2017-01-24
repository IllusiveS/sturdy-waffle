//
// Created by zengel on 1/22/17.
//

#include <Gra/Matma/Vector2.h>
#include <future>
#include "EnemyManager.h"
#include "Enemy.h"
#include "Strafer.h"
#include "Charger.h"
#include "Shooter.h"
#include "Asteroid.h"
#include "Boss.h"


void EnemyManager::spawnWaves() {

}

void EnemyManager::Tick(float delta) {
    long now = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()).count();

    if (now - startTime > waitTime) {
        spawnWave();
	    startTime = duration_cast<milliseconds>(
			    system_clock::now().time_since_epoch()).count();
    }
}

void EnemyManager::ReadScript(lua_State *L) {
    using namespace luabridge;
    if (luaL_dofile(L, "Lua/EnemySpawner.lua") == 0) { // script has opened
        LuaRef table = getGlobal(L, "enemies");
        if (table.isTable()) {
            if (table["spawnWave"].isFunction()) {
                spawnFunc = std::make_shared<LuaRef>(table["spawnWave"]);
            } else {
                spawnFunc.reset();
            }
        }
    } else {
        std::cout << "Error, can't open script!" << std::endl;
    }
	SetupSpawners();
}



void EnemyManager::ExportLua(lua_State *L) {
	using namespace luabridge;
	getGlobalNamespace(L)
			.beginNamespace("enemies")
			.beginClass<EnemyManager>("manager")
			.addProperty("waitTime", &EnemyManager::GetWaitTime, &EnemyManager::SetWaitTime)
			.addFunction("spawnEnemy", &EnemyManager::SpawnEnemy)
			.endClass()
			.endNamespace();
}

void EnemyManager::SetWaitTime(long time) {
	this->waitTime = time;
}

long EnemyManager::GetWaitTime() const {
	return waitTime;
}

void EnemyManager::SpawnEnemy(Vector2 pos, std::string type) {
	auto it = spawners.find(type);
	if (it != spawners.end()){
		CreateFunc f = it->second;
		f(this, pos);
	}
}

void EnemyManager::CreateCharger(Vector2 pos) {
	new Charger(pos);
}

void EnemyManager::CreateShooter(Vector2 pos) {
	new Shooter(pos);
}

void EnemyManager::CreateStraferUp(Vector2 pos) {
	new Strafer(pos, true);
}

void EnemyManager::CreateStraferDown(Vector2 pos) {
	new Strafer(pos, false);
}

void EnemyManager::CreateAsteroid(Vector2 pos) {
	new Asteroid(pos);
}

void EnemyManager::CreateBoss(Vector2 pos) {
	new Boss(pos);
}

void EnemyManager::SetupSpawners() {
	spawners.insert(std::pair<std::string, CreateFunc>("boss", &EnemyManager::CreateBoss));
	spawners.insert(std::pair<std::string, CreateFunc>("shooter", &EnemyManager::CreateShooter));
	spawners.insert(std::pair<std::string, CreateFunc>("charger", &EnemyManager::CreateCharger));
	spawners.insert(std::pair<std::string, CreateFunc>("asteroid", &EnemyManager::CreateAsteroid));
	spawners.insert(std::pair<std::string, CreateFunc>("straferUp", &EnemyManager::CreateStraferUp));
	spawners.insert(std::pair<std::string, CreateFunc>("straferDown", &EnemyManager::CreateStraferDown));
}

void EnemyManager::spawnWave() {
	if (spawnFunc) {
		try {
			(*spawnFunc)(this);
		}
		catch (luabridge::LuaException const &e) {
			std::cout << "LuaException: " << e.what() << std::endl;
		}
	}
}
