//
// Created by wysockipatryk on 1/7/17.
//

#include <iostream>
#include <Gra/Game.h>
#include "Player.h"

Player::Player() : x(0), y(0), dx(0), dy(0), speed(100), IRenderable(), ITickable(), IPhisicsable() {
	tex = Game::GetGame()->GetTextureManager()->GetTexture("player");
}

void Player::Move(Vector2 vec) {
	dx = vec.x;
	dy = vec.y;
}


void Player::Render(SDL_Renderer *renderer) {
	tex->render(x, y);
}

void Player::Tick(float delta) {
	if (tickFunc) {
		try{
			(*tickFunc)(this, delta);
		}
		catch (luabridge::LuaException const& e) {
			std::cout << "LuaException: " << e.what() << std::endl;
		}
	}
}

void Player::ReadScript(lua_State *L) {
	using namespace luabridge;
	if (luaL_dofile(L, "Lua/Characters/Player.lua") == 0) { // script has opened
		LuaRef table = getGlobal(L, "player");
		if (table.isTable()) {
			if (table["speed"].isNumber()) {
				speed = table["speed"];
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

void Player::CalculatePhisics(float delta) {
	x += dx;
	y += dy;
	dx = dx / 2;
	dy = dy / 2;
}

void Player::Position(Vector2 vec) {
	this->x = (int)vec.x;
	this->y = (int)vec.y;
}

void Player::SetSpeed(float speed) {
	this->speed = speed;
}

float Player::GetSpeed () const {
	return speed;
}

void Player::ExportLua(lua_State *L) {
	using namespace luabridge;
	getGlobalNamespace(L)
			.beginNamespace("Player")
					.beginClass<Player>("Player")
					.addFunction("move", &Player::Move)
					.addFunction("position", &Player::Position)
					.addProperty("speed", &Player::GetSpeed, &Player::SetSpeed)
					.endClass()
			.endNamespace();
}

