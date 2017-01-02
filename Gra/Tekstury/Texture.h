//
// Created by wysockipatryk on 1/2/17.
//

#ifndef SDLPODSTAWA_EXE_TEXTURE_H
#define SDLPODSTAWA_EXE_TEXTURE_H

#include <string>
#include <SDL_render.h>

class Texture {
public:
	//Initializes variables
	Texture();

	//Deallocates memory
	~Texture();

	//Deallocates texture
	void free();

	bool createTextureFromFile(std::string path);

	//Renders texture at given point
	void render( int x, int y );

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//Loads image at specified path
	SDL_Surface * loadFromFile(std::string path );
	SDL_Texture * generateTexture(SDL_Surface * surface);

	//The actual hardware texture
	SDL_Texture * mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};


#endif //SDLPODSTAWA_EXE_TEXTURE_H
