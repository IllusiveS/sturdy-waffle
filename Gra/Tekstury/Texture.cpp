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

void Texture::free() {
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Texture::render(int x, int y, SDL_Renderer * renderer) {
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	int result = SDL_RenderCopy( renderer, mTexture, NULL, &renderQuad );
	if(result != 0){
		printf("[err]Cant render ERROR: %s\n", SDL_GetError());
	}
}

int Texture::getWidth() {
	return mWidth;
}

int Texture::getHeight() {
	return mHeight;
}

SDL_Texture *Texture::generateTexture(std::string path) {
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( Game::GetGame()->GetRenderer(), loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

bool Texture::createTextureFromFile(std::string path) {
	bool returnValue = false;
	SDL_Texture * tex = generateTexture(path);
	if(tex == NULL) {
		returnValue = false;
	} else {
		returnValue = true;
//		mWidth = surface->w;
//		mHeight = surface->h;
	}
	mTexture = tex;
	return returnValue;
}
