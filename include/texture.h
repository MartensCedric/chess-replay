#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
struct Texture
{
	Texture(const int width, const int height) : width(width), height(height){}
	SDL_Texture* texture;
	const int width;
	const int height;
};
#endif
