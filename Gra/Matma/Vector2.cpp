//
// Created by wysockipatryk on 1/7/17.
//

#include <cmath>
#include "Vector2.h"

void Vector2::ExportLua(lua_State *L) {
	using namespace luabridge;
	getGlobalNamespace (L)
	.beginNamespace ("math")
			.beginClass <Vector2> ("Vector2")
			.addData ("x", &Vector2::x)
			.addData ("y", &Vector2::y)
			.addFunction ("add", &Vector2::add)
			.addFunction ("multiply", &Vector2::multiply)
			.addFunction ("length", &Vector2::length)
			.addFunction ("normalized", &Vector2::normalized)
			.endClass()
	.endNamespace();
}

Vector2 Vector2::add(Vector2 vec) {
	return Vector2(x + vec.x, y + vec.y);
}

Vector2 Vector2::multiply(Vector2 vec) {
	return Vector2(x * vec.x, y * vec.y);
}

Vector2 Vector2::normalized() {
	double len = length();
	return Vector2(x / len, y / len);
}

double Vector2::length() {
	return pow((pow(x, 2) + pow(y, 2)), 0.5) ;
}

Vector2::Vector2() : x(0), y(0) {

}

Vector2::Vector2(double x, double y) : x(x), y(y) {

}
