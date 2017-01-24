--
-- Created by IntelliJ IDEA.
-- User: wysockipatryk
-- Date: 1/24/17
-- Time: 2:22 PM
-- To change this template use File | Settings | File Templates.
--

enemies = {
    waves = 0,
    spawnWave = function(enemyManager)
        local wavesCreators = {
            enemies.chargersWave,
            enemies.strafersWave
        }

        if(enemies.waves == 3) then
            enemies.spawnBoss(enemyManager);
        else
            print(#wavesCreators)
            wavesCreators[math.random(#wavesCreators)](enemyManager)
        end

    end,
    spawnBoss = function(enemyManager)
        local position = MATH.Vector2(600, 300)
        enemyManager:spawnEnemy(position, "boss")
        enemies.waves = enemies.waves + 1
    end,
    chargersWave = function(enemyManager)
        enemyManager:spawnEnemy(MATH.Vector2(800, 100), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(800, 300), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(800, 500), "charger")

        enemyManager:spawnEnemy(MATH.Vector2(1200, 600), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1200, 700), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1200, 300), "charger")

        enemyManager:spawnEnemy(MATH.Vector2(1600, 400), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1600, 500), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1600, 600), "charger")
        enemyManager.waitTime = 6000
        enemies.waves = enemies.waves + 1
    end,
    strafersWave = function(enemyManager)
        enemyManager:spawnEnemy(MATH.Vector2(800, 100), "straferUp")
        enemyManager:spawnEnemy(MATH.Vector2(1000, 200), "straferDown")
        enemyManager:spawnEnemy(MATH.Vector2(1200, 300), "straferUp")

        enemyManager:spawnEnemy(MATH.Vector2(1400, 400), "straferUp")
        enemyManager:spawnEnemy(MATH.Vector2(1600, 500), "straferDown")
        enemyManager:spawnEnemy(MATH.Vector2(1800, 400), "straferUp")

        enemyManager:spawnEnemy(MATH.Vector2(2000, 300), "straferUp")
        enemyManager:spawnEnemy(MATH.Vector2(2200, 200), "straferDown")
        enemyManager:spawnEnemy(MATH.Vector2(2400, 100), "straferUp")

        enemyManager.waitTime = 6000
        enemies.waves = enemies.waves + 1
    end
}

