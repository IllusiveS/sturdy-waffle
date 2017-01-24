--
-- Created by IntelliJ IDEA.
-- User: wysockipatryk
-- Date: 1/24/17
-- Time: 2:22 PM
-- To change this template use File | Settings | File Templates.
--

enemies = {
    spawnWave = function(enemyManager)
        enemyManager.waitTime = 3000
        local position = MATH.Vector2(400, 300)
        enemyManager:spawnEnemy(position, "boss")
        print("enemy created")
    end
}

