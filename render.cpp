#include "render.h" 
#include <stdio.h>

Render::Render(SDL_Window* window)
{
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(this->renderer == NULL)
	{
		printf("Failed to create renderer -> %s\n", SDL_GetError()); 
	}
}

void Render::drawBoard(int x, int y, int w, int h)
{
	SDL_Rect fillRect = {x, y, w, h};
	SDL_SetRenderDrawColor(renderer, 0x9B, 0x4C, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}

void Render::clear()
{
	this->clear(0xFF, 0xFF, 0xFF, 0xFF);
}

void Render::clear(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
	SDL_RenderClear(this->renderer);
}

void Render::update()
{
	SDL_RenderPresent(this->renderer);
}
