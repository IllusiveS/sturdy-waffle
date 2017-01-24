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

	SetupSpawners();
}

void EnemyManager::Tick(float delta) {
    long now = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()).count();

    if (now - startTime > 3000 && !wave1) {
        spawnWave1();
        wave1 = true;
    }

    if (now - startTime > 9000 && !wave2) {
        spawnWave2();
        wave2 = true;
    }

    if (now - startTime > 17000 && !wave3) {
        spawnWave3();
        wave3 = true;
    }

    if (now - startTime > 22000 && !wave4) {
        spawnWave4();
        wave4 = true;
    }

    if (now - startTime > 27000 && !wave5) {
        spawnWave5();
        wave5 = true;
    }

    if (now - startTime > 37000 && !wave6) {
        spawnWave6();
        wave6 = true;
    }

    if (now - startTime > 47000 && !finalWave) {
        spawnFinalWave();
        finalWave = true;
    }


}

void EnemyManager::spawnWave1() {
    Charger *chargerA = new Charger(Vector2(800, 100));
    Charger *chargerB = new Charger(Vector2(800, 300));
    Charger *chargerC = new Charger(Vector2(800, 500));

    Charger *chargerD = new Charger(Vector2(1200, 50));
    Charger *chargerE = new Charger(Vector2(1200, 150));
    Charger *chargerF = new Charger(Vector2(1200, 250));

    Charger *chargerG = new Charger(Vector2(1600, 350));
    Charger *chargerH = new Charger(Vector2(1600, 450));
    Charger *chargerI = new Charger(Vector2(1600, 550));


}

void EnemyManager::spawnWave2() {
    Strafer *straferA = new Strafer(Vector2(800, 100), true);
    Strafer *straferB = new Strafer(Vector2(1000, 200), false);
    Strafer *straferC = new Strafer(Vector2(1200, 300), true);
    Strafer *straferD = new Strafer(Vector2(1400, 400), false);
    Strafer *straferE = new Strafer(Vector2(1600, 500), true);
    Strafer *straferF = new Strafer(Vector2(1800, 400), false);
    Strafer *straferG = new Strafer(Vector2(2000, 300), true);
    Strafer *straferH = new Strafer(Vector2(2200, 200), false);
    Strafer *straferI = new Strafer(Vector2(2400, 100), true);


//

}

void EnemyManager::spawnWave3() {
    Shooter *shooterA = new Shooter(Vector2(1200, 300));


}

void EnemyManager::spawnWave4() {
    Charger *chargerA = new Charger(Vector2(800, 50));
    Charger *chargerB = new Charger(Vector2(800, 550));

    Charger *chargerC = new Charger(Vector2(1000, 100));
    Charger *chargerD = new Charger(Vector2(1000, 500));

    Charger *chargerE = new Charger(Vector2(1200, 150));
    Charger *chargerF = new Charger(Vector2(1200, 450));

    Charger *chargerG = new Charger(Vector2(1400, 200));
    Charger *chargerH = new Charger(Vector2(1400, 400));

    Charger *chargerI = new Charger(Vector2(1600, 250));
    Charger *chargerJ = new Charger(Vector2(1600, 350));

    Charger *chargerK = new Charger(Vector2(1800, 300));


}

void EnemyManager::spawnWave5() {
    Asteroid *asteroidA = new Asteroid(Vector2(800, 150));
    Asteroid *asteroidB = new Asteroid(Vector2(1400, 450));
    Asteroid *asteroidC = new Asteroid(Vector2(1600, 350));
    Asteroid *asteroidD = new Asteroid(Vector2(1800, 200));
    Asteroid *asteroidE = new Asteroid(Vector2(2100, 500));
    Asteroid *asteroidF = new Asteroid(Vector2(2300, 100));
    Asteroid *asteroidG = new Asteroid(Vector2(2450, 400));
    Asteroid *asteroidH = new Asteroid(Vector2(2600, 550));
    Asteroid *asteroidI = new Asteroid(Vector2(2850, 200));
    Asteroid *asteroidJ = new Asteroid(Vector2(3000, 50));


}

void EnemyManager::spawnWave6() {
    Charger *chargerA = new Charger(Vector2(800, 100));
    Charger *chargerB = new Charger(Vector2(800, 500));

    Charger *chargerC = new Charger(Vector2(1000, 200));
    Charger *chargerD = new Charger(Vector2(1000, 400));

    Strafer *straferA = new Strafer(Vector2(1200, 100), true);
    Strafer *straferB = new Strafer(Vector2(1400, 200), false);
    Strafer *straferC = new Strafer(Vector2(1600, 300), true);
    Strafer *straferD = new Strafer(Vector2(1800, 200), false);

    Strafer *straferE = new Strafer(Vector2(1600, 500), true);
    Strafer *straferF = new Strafer(Vector2(1800, 400), false);
    Strafer *straferG = new Strafer(Vector2(2000, 300), true);
    Strafer *straferH = new Strafer(Vector2(2200, 200), false);

    Shooter *shooterA = new Shooter(Vector2(1000, 300));

    Asteroid *asteroidB = new Asteroid(Vector2(1400, 200));
    Asteroid *asteroidC = new Asteroid(Vector2(1600, 500));
}

void EnemyManager::spawnFinalWave() {
    Boss * boss = new Boss(Vector2(1000,300));
}

void EnemyManager::ReadScript(lua_State *L) {
    using namespace luabridge;
    if (luaL_dofile(L, "Lua/EnemySpawner.lua") == 0) { // script has opened
        LuaRef table = getGlobal(L, "EnemyManager");
        if (table.isTable()) {
            if (table["spawnWave"].isFunction()) {
                spawnFunc = std::make_shared<LuaRef>(table["spawnEnemy"]);
            } else {
                spawnFunc.reset();
            }
        }
    } else {
        std::cout << "Error, can't open script!" << std::endl;
    }
}



void EnemyManager::ExportLua(lua_State *L) {
	using namespace luabridge;
	getGlobalNamespace(L)
			.beginNamespace("EnemyManager")
			.beginClass<EnemyManager>("EnemyManager")
			.addFunction("spawnEnemy", &EnemyManager::SpawnEnemy)
			.endClass()
			.endNamespace();
}

void EnemyManager::SpawnEnemy(Vector2 pos, std::string type) {
	spawners[type](this, pos);
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
