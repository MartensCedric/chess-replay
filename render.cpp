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
	SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(this->renderer);

	SDL_Rect fillRect = {SCREEN_WIDTH/4, SCREEN_HEIGHT/4, SCREEN_WIDTH/2, SCREEN_HEIGHT/2};
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
}

void Render::update()
{
	SDL_RenderPresent(this->renderer);
}
