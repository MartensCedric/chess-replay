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
	Render r(screen->getWindow());
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
		r.clear(0x00, 0x00, 0x00, 0xFF);
		r.drawBoard(50, 50, 550, 550);
		r.update();
	}	
	screen->close();
	return 0;
}
