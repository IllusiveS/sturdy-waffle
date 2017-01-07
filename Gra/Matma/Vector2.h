//
// Created by wysockipatryk on 1/7/17.
//

#ifndef SDLPODSTAWA_EXE_VECTOR2_H
#define SDLPODSTAWA_EXE_VECTOR2_H

#include <lua.hpp>
#include <LuaBridge/LuaBridge.h>

class Vector2 {
public:
	Vector2();
	Vector2(double x, double y);

	double x;
	double y;

	static void ExportLua(lua_State * L);

	Vector2 add(Vector2 vec);
	Vector2 multiply(Vector2 vec);
	Vector2 normalized();
	double length();
};


#endif //SDLPODSTAWA_EXE_VECTOR2_H
