//
// Created by wysockipatryk on 1/17/17.
//

#ifndef SDLPODSTAWA_EXE_AABB_H
#define SDLPODSTAWA_EXE_AABB_H


#include <Gra/Matma/Vector2.h>

struct AABB {
	AABB(Vector2 center, Vector2 halfSize);

	bool Overlaps(AABB other);

	Vector2 center;
	Vector2 halfSize;
};


#endif //SDLPODSTAWA_EXE_AABB_H
