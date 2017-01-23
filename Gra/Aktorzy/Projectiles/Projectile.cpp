//
// Created by zengel on 1/22/17.
//

#include <Gra/Game.h>
#include "Projectile.h"

Projectile::Projectile(Vector2 position) : IRenderable(), ITickable(), IPhysicsable() {

    StartingPosition(position);
    Position(position);
}

void Projectile::Move(Vector2 vec) {
    speedVector.x = vec.x;
    speedVector.y = vec.y;
}


void Projectile::Render(SDL_Renderer *renderer) {
    tex->render((int)position.x, (int)position.y);
}

void Projectile::Tick(float delta) {
    Move(Vector2(speedX*delta, 0));
}

void Projectile::ReadScript(lua_State *L) {
    using namespace luabridge;
    if (luaL_dofile(L, "Lua/Characters/Projectile.lua") == 0) { // script has opened
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

void Projectile::Position(Vector2 vec) {
    this->position.x = (int)vec.x;
    this->position.y = (int)vec.y;
}

void Projectile::StartingPosition(Vector2 vec) {
    this->startingPosition.x = (int)vec.x;
    this->startingPosition.y = (int)vec.y;
}

void Projectile::SetSpeed(float speed) {
    this->speedX = speed;
}

float Projectile::GetSpeed () const {
    return speedX;
}

void Projectile::ExportLua(lua_State *L) {
    using namespace luabridge;
    getGlobalNamespace(L)
            .beginNamespace("Projectile")
            .beginClass<Projectile>("Projectile")
            .addFunction("move", &Projectile::Move)
            .addFunction("position", &Projectile::Position)
            .addProperty("speed", &Projectile::GetSpeed, &Projectile::SetSpeed)
            .endClass()
            .endNamespace();
}

void Projectile::collide(IPhysicsable *coll) {
    if(coll->type == "EnemyKillingBox") {
        Destroy();
    }
}