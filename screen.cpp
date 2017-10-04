#include "screen.h"
#include <iostream>

Screen::Screen(int width, int height)
	: width(width), height(height)
{}

void Screen::createWindow()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error : %s\n", SDL_GetError());
	}else{
		this->window = SDL_CreateWindow("Chess Replay", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		if(window == NULL)
		{
			printf("Window could not be created! SDL_Error : %s\n", SDL_GetError());
		}
	}
}

void Screen::close()
{
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}
