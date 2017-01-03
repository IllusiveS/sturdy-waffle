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
	void render( int x, int y, SDL_Renderer * renderer);

	//Gets image dimensions
	int getWidth();
	int getHeight();
	//The actual hardware texture
	SDL_Texture * mTexture;
private:
	//Loads image at specified path
	SDL_Texture * generateTexture(std::string path);
	Texture(const Texture& that) = delete;


	//Image dimensions
	int mWidth;
	int mHeight;
};


#endif //SDLPODSTAWA_EXE_TEXTURE_H
