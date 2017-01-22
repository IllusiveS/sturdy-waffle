//
// Created by zengel on 1/22/17.
//

#ifndef SDLPODSTAWA_EXE_ENEMY_H
#define SDLPODSTAWA_EXE_ENEMY_H


#include <memory>
#include <Gra/Aktorzy/ITickable.h>
#include <Gra/Aktorzy/Actor.h>
#include <Gra/Matma/Vector2.h>
#include <Gra/Aktorzy/IRenderable.h>
#include <Gra/Aktorzy/IPhysicsable.h>
#include <Gra/Tekstury/Texture.h>
class Enemy : private Actor, protected ITickable, protected IRenderable, protected IPhysicsable {
public:
    void Move(Vector2 vec);
    void Position(Vector2 vec);
    void StartingPosition(Vector2 vec);

    void SetSpeed(float speed);
    float GetSpeed () const;

    void ReadScript(lua_State * L);
    static void ExportLua(lua_State *L);
protected:
    Texture * tex;
    float speedX;
    float speedY;
    Enemy(Vector2 position);
private:
    void Render(SDL_Renderer *renderer) override;

    void collide(IPhysicsable *coll) override;

    void Tick(float delta) override;
    std::shared_ptr<luabridge::LuaRef> tickFunc;
};


#endif //SDLPODSTAWA_EXE_ENEMY_H
