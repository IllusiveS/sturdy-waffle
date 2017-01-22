//
// Created by zengel on 1/22/17.
//

#include <Gra/Game.h>
#include <Gra/Aktorzy/IPhysicsable.h>
#include "Enemy.h"

Enemy::Enemy(Vector2 position) : IRenderable(), ITickable(), IPhysicsable() {
    tex = Game::GetGame()->GetTextureManager()->GetTexture("enemy");
    StartingPosition(position);
    Position(position);
}

void Enemy::Move(Vector2 vec) {
    speedVector.x = vec.x;
    speedVector.y = vec.y;
}


void Enemy::Render(SDL_Renderer *renderer) {
    tex->render((int)position.x, (int)position.y);
}

void Enemy::Tick(float delta) {
    Move(Vector2(speedX*delta, 0));
}

void Enemy::ReadScript(lua_State *L) {
    using namespace luabridge;
    if (luaL_dofile(L, "Lua/Characters/Enemy.lua") == 0) { // script has opened
        LuaRef table = getGlobal(L, "player");
        if (table.isTable()) {
            if (table["speedVector"].isNumber()) {
                speedX = table["speedVector"];
            }
            if (table["tick"].isFunction()) {
                tickFunc = std::make_shared<LuaRef>(table["tick"]);
            } else {
                tickFunc.reset();
            }
        }
    } else {
        std::cout << "Error, can't open script!" << std::endl;
    }
}

void Enemy::Position(Vector2 vec) {
    this->position.x = (int)vec.x;
    this->position.y = (int)vec.y;
}

void Enemy::StartingPosition(Vector2 vec) {
    this->startingPosition.x = (int)vec.x;
    this->startingPosition.y = (int)vec.y;
}

void Enemy::SetSpeed(float speed) {
    this->speedX = speed;
}

float Enemy::GetSpeed () const {
    return speedX;
}

void Enemy::ExportLua(lua_State *L) {
    using namespace luabridge;
    getGlobalNamespace(L)
            .beginNamespace("Enemy")
            .beginClass<Enemy>("Enemy")
            .addFunction("move", &Enemy::Move)
            .addFunction("position", &Enemy::Position)
            .addProperty("speed", &Enemy::GetSpeed, &Enemy::SetSpeed)
            .endClass()
            .endNamespace();
}

void Enemy::collide(IPhysicsable *coll) {
    std::cout << "przeciwnik ma kolizję" << std::endl;

}