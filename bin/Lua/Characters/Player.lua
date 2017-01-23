--
-- Created by IntelliJ IDEA.
-- User: wysockipatryk
-- Date: 1/9/17
-- Time: 5:06 PM
-- To change this template use File | Settings | File Templates.
--

player = {
    speed = 8,
    tick = function(player, delta)
        local InputX = Game:getGame():getInputManager():checkInput("right")
        local InputY = Game:getGame():getInputManager():checkInput("up")
        local Xmovement = delta * InputX
        local YMovement = delta * InputY
        local deltaSpeed = delta * player.speed
        local InputVector = MATH.Vector2(Xmovement, YMovement)
        local NormalizedVector = InputVector:normalized()
        player:move(NormalizedVector:multiplyByScalar(deltaSpeed))
    end
}

