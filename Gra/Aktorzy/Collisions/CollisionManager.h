//
// Created by wysockipatryk on 1/18/17.
//

#ifndef SDLPODSTAWA_EXE_COLLISIONMANAGER_H
#define SDLPODSTAWA_EXE_COLLISIONMANAGER_H

#include <Gra/Aktorzy/IPhysicsable.h>
#include <list>

struct PotentialIntersection {

};

class CollisionManager {

public:
	void processPhysics(float delta);

	void subscribePhysicable(IPhysicsable * object);
	void unSubscribePhysicable(IPhysicsable * object);
private:
	std::list<IPhysicsable *> objects;

	void calculatePhysics(std::pair<SweepData, std::list<SweepData>> pair);
};


#endif //SDLPODSTAWA_EXE_COLLISIONMANAGER_H
