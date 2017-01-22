//
// Created by wysockipatryk on 12/26/16.
//
#include <iostream>
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
	SDL_PumpEvents();
	setInputValue("up", 0);
	setInputValue("right", 0);
	setInputValue("fire", 0);

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDLK_RETURN]) {
		printf("<RETURN> is pressed.\n");
	}
	if (state[SDL_SCANCODE_RIGHT]) {
		addInputValue("right", 1);
	}
	if (state[SDL_SCANCODE_LEFT]) {
		addInputValue("right", -1);
	}
	if (state[SDL_SCANCODE_UP]) {
		addInputValue("up", -1);
	}
	if (state[SDL_SCANCODE_DOWN]) {
		addInputValue("up", 1);
	}

	while (SDL_PollEvent(&e) != 0) {
		//User requests quit
		if (e.type == SDL_QUIT) {
			//Wychodzimy
		}
			//User presses a key
		else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
				case SDLK_SPACE:
					setInputValue("fire", 1);
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
