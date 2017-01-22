//
// Created by wysockipatryk on 1/7/17.
//

#include <iostream>
#include <Gra/Game.h>
#include <Gra/Aktorzy/Projectiles/PlayerProjectile.h>
#include <chrono>
#include "Player.h"

using namespace std::chrono;

Player::Player() : speed(250), IRenderable(), ITickable(), IPhysicsable() {
    tex = Game::GetGame()->GetTextureManager()->GetTexture("player");
    Position(Vector2(0, Game::GetGame()->SCREEN_HEIGHT / 2));
}

void Player::Move(Vector2 vec) {
    speedVector.x = vec.x;
    speedVector.y = vec.y;
}


void Player::Render(SDL_Renderer *renderer) {
    tex->render((int) position.x, (int) position.y);
}

void Player::Tick(float delta) {
    if (tickFunc) {
        try {
            (*tickFunc)(this, delta);
        }
        catch (luabridge::LuaException const &e) {
            std::cout << "LuaException: " << e.what() << std::endl;
        }
    }
}

void Player::ReadScript(lua_State *L) {
    using namespace luabridge;
    if (luaL_dofile(L, "Lua/Characters/Player.lua") == 0) { // script has opened
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

void Player::Fire() {

    if (duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()).count() - old > 400) {
        PlayerProjectile *proj = new PlayerProjectile(Vector2(position.x, position.y));

        old = duration_cast<milliseconds>(
                system_clock::now().time_since_epoch()).count();
    }

}

void Player::Position(Vector2 vec) {
    this->position.x = (int) vec.x;
    this->position.y = (int) vec.y;
}

void Player::SetSpeed(float speed) {
    this->speed = speed;
}

float Player::GetSpeed() const {
    return speed;
}

void Player::ExportLua(lua_State *L) {
    using namespace luabridge;
    getGlobalNamespace(L)
            .beginNamespace("Player")
            .beginClass<Player>("Player")
            .addFunction("move", &Player::Move)
            .addFunction("position", &Player::Position)
            .addFunction("fire", &Player::Fire)
            .addProperty("speed", &Player::GetSpeed, &Player::SetSpeed)
            .endClass()
            .endNamespace();
}

void Player::collide(IPhysicsable *coll) {
    std::cout << "gracz ma kolizję" << std::endl;

}

