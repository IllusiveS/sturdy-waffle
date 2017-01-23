//
// Created by wysockipatryk on 1/7/17.
//

#ifndef SDLPODSTAWA_EXE_PLAYER_H
#define SDLPODSTAWA_EXE_PLAYER_H


#include <Gra/Aktorzy/ITickable.h>
#include <Gra/Aktorzy/Actor.h>
#include <Gra/Matma/Vector2.h>
#include <Gra/Aktorzy/IRenderable.h>
#include <Gra/Aktorzy/IPhysicsable.h>
#include <Gra/Tekstury/Texture.h>
#include <memory>
class Player : public Actor, private ITickable, private IRenderable, public IPhysicsable {
public:
	Player();
	virtual ~Player();
	void Move(Vector2 vec);
	void Position(Vector2 vec);

	void SetSpeed(float speed);
	float GetSpeed () const;

	void ReadScript(lua_State * L);
	static void ExportLua(lua_State *L);
private:
	long old;
	Texture * tex;
	float speed;
	void Fire();
private:
	void Render(SDL_Renderer *renderer) override;

	void collide(IPhysicsable *coll) override;

	void Tick(float delta) override;
	std::shared_ptr<luabridge::LuaRef> tickFunc;

};


#endif //SDLPODSTAWA_EXE_PLAYER_H
