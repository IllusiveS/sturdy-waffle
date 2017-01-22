//
// Created by wysockipatryk on 1/7/17.
//

#ifndef SDLPODSTAWA_EXE_IPHISICSABLE_H
#define SDLPODSTAWA_EXE_IPHISICSABLE_H


#include <Gra/Matma/Vector2.h>
#include <Gra/Aktorzy/Collisions/AABB.h>
#include <Gra/Aktorzy/Collisions/SweepData.h>

class IPhysicsable {
public:
	IPhysicsable();
	~IPhysicsable();

	Vector2 startingPosition;
	Vector2 oldPosition;
	Vector2 position;
	Vector2 oldSpeed;
	Vector2 speedVector;
	Vector2 scale;

	AABB aabb;
	Vector2 aabbOffset;

	double rotation;

	virtual void CalculatePhysics(float delta);
	virtual void collide(IPhysicsable * coll) = 0;

	SweepData getBeginSweepData();
	SweepData getEndSweepData();

	bool checkCollision(IPhysicsable * other);
};

#endif //SDLPODSTAWA_EXE_IPHISICSABLE_H
