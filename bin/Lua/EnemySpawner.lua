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
        if(enemies.waves == 1) then
            enemies.spawnBoss(enemyManager);
        else
            enemies.spawnEasyWave(enemyManager);
        end

    end,
    spawnBoss = function(enemyManager)
        local position = MATH.Vector2(600, 300)
        enemyManager:spawnEnemy(position, "boss")
        enemies.waves = enemies.waves + 1
    end,
    spawnEasyWave = function(enemyManager)
        enemyManager:spawnEnemy(MATH.Vector2(1000, 300), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1000, 400), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1000, 500), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1000, 600), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1000, 700), "charger")
        enemyManager.waitTime = 6000
        enemies.waves = enemies.waves + 1
    end
}

