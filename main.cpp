#include <iostream>
#include <Gra/Game.h>
#include <SDL.h>
#include <thread>
//#include "LuaBridge/LuaBridge.h"
#include <chrono>
#include <Gra/Aktorzy/Mapa/GameMap.h>

int main(int argc, char * args[]) {
	using namespace std::chrono;
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return 1;
	}
	//Set texture filtering to linear
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
		printf( "Warning: Linear texture filtering not enabled!" );
	}
    Game::Setup();
	Game * gra = Game::GetGame();
	GameMap * mapa = new GameMap();
	mapa->ReadMapFromFile("Lua/Map.lua");
	for( ; !gra->isFinished; ) {
		gra->UpdateInput();
		gra->UpdateTick();
		gra->UpdatePhysics();
		gra->Render();
		std::chrono::seconds sec(1);
		std::this_thread::sleep_for(sec);
	}
	//Odpalamy pętlę
		//Sprawdzamy input
		//Robimy update na każdym obiekcie
		//Renderujemy syf
	Game::Close();
    return 0;
}