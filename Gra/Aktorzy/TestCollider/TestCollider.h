//
// Created by wysockipatryk on 1/20/17.
//

#ifndef SDLPODSTAWA_EXE_TESTCOLLIDER_H
#define SDLPODSTAWA_EXE_TESTCOLLIDER_H


class Actor;
class IRenderable;
class IPhysicsable;
class Texture;

class TestCollider : public Actor, public IPhysicsable, public IRenderable {
public:
	TestCollider();
public:
	void collide(IPhysicsable *coll) override;
	void Render(SDL_Renderer *renderer) override;
protected:
	Texture * tex;
};


#endif //SDLPODSTAWA_EXE_TESTCOLLIDER_H
