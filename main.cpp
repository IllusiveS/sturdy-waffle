#include <iostream>
#include <Gra/Game.h>
#include <SDL.h>
#include <thread>
#include <chrono>
#include <Gra/Aktorzy/Mapa/GameMap.h>

using std::this_thread::sleep_for;

int main(int argc, char *args[]) {
    using namespace std::chrono;
    double fps = 60.0;
    double delta = 1.0 / fps;
    auto t0 = std::chrono::system_clock::now();
    unsigned long int frame = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return 1;
    }
    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled!");
    }
    Game::Setup();
    Game *gra = Game::GetGame();
    //GameMap *mapa = new GameMap();
   // mapa->ReadMapFromFile("Lua/Map.lua");

    for (; !gra->isFinished;) {
        frame++;
        auto sleepTime = microseconds((int) (1000000.0 * (((double) frame) / fps -
                                                          (((std::chrono::duration<double>) (system_clock::now() -
                                                                                             t0)).count()))));
        sleep_for(sleepTime);
        auto now = system_clock::now();
//stufff test
        gra->UpdateInput();
        gra->UpdateTick(delta);
        gra->RemoveUnusedActors();
        gra->UpdatePhysics(delta);
        gra->Render();

        if ( frame > 100000000 ) {
            t0 = std::chrono::system_clock::now();
            frame = 0;
        }
    }
    //Odpalamy pętlę
    //Sprawdzamy input
    //Robimy update na każdym obiekcie
    //Renderujemy syf
    Game::Close();
    return 0;
}