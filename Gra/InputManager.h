//
// Created by wysockipatryk on 12/26/16.
//

#ifndef SDLPODSTAWA_INPUTMANAGER_H
#define SDLPODSTAWA_INPUTMANAGER_H

#include <string>
#include <map>
#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

//Klasa do wykrywania inputu
class InputManager {
public:
	InputManager();
	void ExportLua(lua_State *L);
	//TODO funkcja to zrobienia statyczną
	float IsButtonPressed(std::string key);
	void UpdateInputs();
private:
	std::map<std::string, float> inputs;
	void addInputValue(std::string key, float value);
	void setInputValue(std::string key, float value);
};


#endif //SDLPODSTAWA_INPUTMANAGER_H
