#include <SDL2/SDL.h>
#include <stdio.h>
#include "pair.h"
#include "render.h"
#include "screen.h"

bool running = true;

int main(int argc, char*  args[])
{
	Screen* screen = new Screen(800, 600);
	screen->createWindow();	
	Render render(screen->getWindow());
	
	SDL_Event e;

	while(running)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				running = false;
			}
		}
		render.clear(0x00, 0x00, 0x00, 0xFF);
		render.drawBoard(56, 56, 544, 544);
		render.update();
	}
	
	screen->close();
	return 0;
}
