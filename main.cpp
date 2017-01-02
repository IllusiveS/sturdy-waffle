#include <iostream>
#include <Gra/Game.h>
#include <SDL.h>
#include <thread>
#include <chrono>

int main(int argc, char * args[]) {
	using namespace std::chrono;
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return 1;
	}
    Game::Setup();
	Game * gra = Game::GetGame();
	for( ; !gra->isFinished; ) {
		gra->UpdateInput();
		gra->UpdateTick();
		gra->UpdatePhysics();
		gra->Render();
	}
	//Odpalamy pętlę
		//Sprawdzamy input
		//Robimy update na każdym obiekcie
		//Renderujemy syf
	std::chrono::seconds sec(5);
	std::this_thread::sleep_for(sec);
	Game::Close();
    return 0;
}