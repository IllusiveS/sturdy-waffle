//
// Created by wysockipatryk on 1/2/17.
//

#include <SDL_image.h>
#include <Gra/Game.h>
#include "Texture.h"

Texture::Texture() : mTexture(NULL), mWidth(0), mHeight(0) {

}

Texture::~Texture() {
	free();
}

SDL_Surface * Texture::loadFromFile(std::string path) {
	free();

	//The final optimized image
	SDL_Surface * optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface * loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "[err]Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, Game::GetGame()->GetSurface()->format, 0);
		if( optimizedSurface == NULL )
		{
			printf( "[err]Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

void Texture::free() {
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Texture::render(int x, int y) {
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopy( Game::GetGame()->GetRenderer(), mTexture, NULL, &renderQuad );
}

int Texture::getWidth() {
	return mWidth;
}

int Texture::getHeight() {
	return mHeight;
}

SDL_Texture *Texture::generateTexture(SDL_Surface * loadedSurface) {
	if(loadedSurface == NULL){

	} else {
		SDL_Texture * newTex = SDL_CreateTextureFromSurface(Game::GetGame()->GetRenderer(), loadedSurface);
		if(newTex == NULL) {

		} else {
			mTexture = newTex;
			SDL_FreeSurface(loadedSurface);
		}
	}
}

bool Texture::createTextureFromFile(std::string path) {
	bool returnValue = false;
	SDL_Surface * surface = loadFromFile(path);
	SDL_Texture * tex = generateTexture(surface);
	if(tex == NULL) {
		returnValue = false;
		printf("[err]Cant read %s \n", path.c_str());
	} else {
		returnValue = true;
		mWidth = surface->w;
		mHeight = surface->h;
		printf("[suc]Created texture for %s \n", path.c_str());
	}
	mTexture = tex;
	return returnValue;
}
