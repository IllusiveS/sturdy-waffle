//
// Created by wysockipatryk on 12/26/16.
//

#include <SDL_keycode.h>
#include <SDL_events.h>
#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include "InputManager.h"

float InputManager::IsButtonPressed(std::string key) {
	auto it = inputs.find(key);
	if (it != inputs.end()) {
		return it->second;
	} else {
		return 0;
	}
}

void InputManager::UpdateInputs() {
	SDL_Event e;
	setInputValue("up", 0);
	setInputValue("right", 0);
	while (SDL_PollEvent(&e) != 0) {
		//User requests quit
		if (e.type == SDL_QUIT) {
			//Wychodzimy
		}
			//User presses a key
		else if (e.type == SDL_KEYDOWN) {
			//Select surfaces based on key press
			switch (e.key.keysym.sym) {
				case SDLK_UP:
					addInputValue("up", -1);
					break;

				case SDLK_DOWN:
					addInputValue("up", 1);
					break;

				case SDLK_LEFT:
					addInputValue("right", -1);
					break;

				case SDLK_RIGHT:
					addInputValue("right", 1);
					break;

				default:
					break;
			}
		}
	}
}

InputManager::InputManager() {
	inputs.insert(std::pair<std::string, float>("up", 0));
	inputs.insert(std::pair<std::string, float>("right", 0));
}

void InputManager::setInputValue(std::string key, float value) {
	auto it = inputs.find(key);
	if (it != inputs.end())
		it->second = value;
}


void InputManager::addInputValue(std::string key, float value) {
	auto it = inputs.find(key);
	if (it != inputs.end())
		it->second = value + it->second;
}

void InputManager::ExportLua(lua_State *L) {
	using namespace luabridge;
	getGlobalNamespace(L)
			.beginNamespace("InputManager")
			.beginClass<InputManager>("InputManager")
			.addFunction("checkInput", &InputManager::IsButtonPressed)
			.endClass();
}
