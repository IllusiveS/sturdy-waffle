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
            enemies.strafersWave,
            enemies.shooterWave,
            enemies.chargerWave2,
            enemies.asteroidWave
        }

        math.randomseed( os.time() )

        if(enemies.waves == 6) then
            enemyManager.waitTime = 1000
            enemies.waves = enemies.waves + 1
        elseif (enemies.waves == 7) then
            enemies.spawnBoss(enemyManager);
        else
            wavesCreators[math.random(#wavesCreators)](enemyManager)
        end

    end,
    spawnBoss = function(enemyManager)
        enemyManager.waitTime = 6000000
        local position = MATH.Vector2(900, 300)
        enemyManager:spawnEnemy(position, "boss")
        enemies.waves = enemies.waves + 1
    end,
    chargersWave = function(enemyManager)
        enemyManager:spawnEnemy(MATH.Vector2(800, 100), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(800, 300), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(800, 500), "charger")

        enemyManager:spawnEnemy(MATH.Vector2(1200, 200), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1200, 400), "charger")

        enemyManager:spawnEnemy(MATH.Vector2(1600, 100), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1600, 300), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1600, 500), "charger")
        enemyManager.waitTime = 4000
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

        enemyManager.waitTime = 3000
        enemies.waves = enemies.waves + 1
    end,
    shooterWave = function(enemyManager)
        enemyManager:spawnEnemy(MATH.Vector2(1200, 300), "shooter")

        enemyManager.waitTime = 5000
        enemies.waves = enemies.waves + 1
    end,
    chargerWave2 = function(enemyManager)
        enemyManager:spawnEnemy(MATH.Vector2(800, 50), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(800, 550), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1000, 100), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1000, 500), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1200, 150), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1200, 450), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1400, 200), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1400, 400), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1600, 250), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1600, 350), "charger")
        enemyManager:spawnEnemy(MATH.Vector2(1800, 300), "charger")

        enemyManager.waitTime = 6000
        enemies.waves = enemies.waves + 1
    end,
    asteroidWave = function(enemyManager)
        enemyManager:spawnEnemy(MATH.Vector2(800, 150), "asteroid")
        enemyManager:spawnEnemy(MATH.Vector2(1400, 450), "asteroid")
        enemyManager:spawnEnemy(MATH.Vector2(1600, 350), "asteroid")
        enemyManager:spawnEnemy(MATH.Vector2(1800, 200), "asteroid")
        enemyManager:spawnEnemy(MATH.Vector2(2100, 500), "asteroid")
        enemyManager:spawnEnemy(MATH.Vector2(2300, 100), "asteroid")

        enemyManager:spawnEnemy(MATH.Vector2(2450, 400), "asteroid")
        enemyManager:spawnEnemy(MATH.Vector2(2600, 550), "asteroid")
        enemyManager:spawnEnemy(MATH.Vector2(2850, 200), "asteroid")
        enemyManager:spawnEnemy(MATH.Vector2(3000, 50), "asteroid")
        enemyManager.waitTime = 5000
        enemies.waves = enemies.waves + 1
    end
}

