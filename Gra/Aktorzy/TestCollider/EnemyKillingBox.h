//
// Created by wysockipatryk on 1/23/17.
//

#ifndef SDLPODSTAWA_EXE_ENEMYKILLINGBOX_H
#define SDLPODSTAWA_EXE_ENEMYKILLINGBOX_H


#include <Gra/Aktorzy/Actor.h>
#include <Gra/Aktorzy/IPhysicsable.h>

class EnemyKillingBox : public Actor, public IPhysicsable{
public:
	EnemyKillingBox();
	virtual ~EnemyKillingBox();
public:
	void collide(IPhysicsable *coll) override;
};


#endif //SDLPODSTAWA_EXE_ENEMYKILLINGBOX_H
