#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
struct Texture
{
	SDL_Texture* texture;
	int width;
	int height;
};
#endif
