//
// Created by wysockipatryk on 1/2/17.
//

#ifndef SDLPODSTAWA_EXE_TEXTURE_H
#define SDLPODSTAWA_EXE_TEXTURE_H

#include <string>
#include <SDL_render.h>

//Texture wrapper class
class Texture
{
public:
	//Initializes variables
	Texture();

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	bool loadFromFile( std::string path );

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render( int x, int y );

	void render( int x, int y, int width, int height,  SDL_Rect Animrect  );

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};


#endif //SDLPODSTAWA_EXE_TEXTURE_H
