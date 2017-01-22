//
// Created by zengel on 1/22/17.
//

#include <Gra/Game.h>
#include <Gra/Aktorzy/IPhysicsable.h>
#include "Enemy.h"

Enemy::Enemy(Vector2 position) : speed(100), IRenderable(), ITickable(), IPhysicsable() {
    tex = Game::GetGame()->GetTextureManager()->GetTexture("enemy");
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
    if (tickFunc) {
        try{
            (*tickFunc)(this, delta);
        }
        catch (luabridge::LuaException const& e) {
            std::cout << "LuaException: " << e.what() << std::endl;
        }
    }
}

void Enemy::ReadScript(lua_State *L) {
    using namespace luabridge;
    if (luaL_dofile(L, "Lua/Characters/Enemy.lua") == 0) { // script has opened
        LuaRef table = getGlobal(L, "player");
        if (table.isTable()) {
            if (table["speedVector"].isNumber()) {
                speed = table["speedVector"];
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

void Enemy::SetSpeed(float speed) {
    this->speed = speed;
}

float Enemy::GetSpeed () const {
    return speed;
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