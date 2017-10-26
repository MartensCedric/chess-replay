#include "render.h" 
#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include "board.h"
#include <string>

Render::Render(SDL_Window* window)
{
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(this->renderer == NULL)
	{
		printf("Failed to create renderer -> %s\n", SDL_GetError()); 
	}
}

void Render::renderTiles(int x, int y, int w, int h)
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			SDL_Rect square = {x, y, w/8, h/8};
			
			if((i + j) % 2 == 0)
			{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0x9B, 0x4C, 0x00, 0xFF);
			}

			square.x = x + j * square.w;
			square.y = y + i * square.h;
	
			SDL_RenderFillRect(renderer, &square);
		}
	}	
}

void Render::render(Texture* texture, int x, int y, int w, int h, SDL_Rect* clip)
{
	SDL_Rect renderQuad = { x, y, w, h };
	if(clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy(this->renderer, texture->texture, clip, &renderQuad);
}

void Render::render(Texture* texture, int x, int y)
{
	render(texture, x, y, texture->width, texture->height, NULL);
}

void Render::render(Texture* texture, int x, int y, int w, int h)
{
	render(texture, x, y, w, h, NULL);
}

void Render::renderPieces(Board* board)
{
 	//TODO implement iterator
	Piece* boardData = board->getBoardData();

	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			
		}
	}
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
