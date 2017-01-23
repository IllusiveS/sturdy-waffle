//
// Created by piorunes on 23.01.17.
//

#ifndef SDLPODSTAWA_EXE_BACKGROUND_H
#define SDLPODSTAWA_EXE_BACKGROUND_H


#include <Gra/Aktorzy/IRenderable.h>
#include <Gra/Tekstury/Texture.h>
#include <Gra/Aktorzy/ITickable.h>

class background : private IRenderable, private ITickable {
public:
    background();
    void SetupTexture(int x, int y, Texture * texture);
private:
    int x, y;
    Texture * texture;
    virtual void Render(SDL_Renderer * renderer);
    void Tick(float delta) override;
    SDL_Rect bgRect;
};

#endif //SDLPODSTAWA_EXE_BACKGROUND_H
