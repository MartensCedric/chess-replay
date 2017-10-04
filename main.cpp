#include <SDL2/SDL.h>
#include <stdio.h>
#include "pair.h"
#include "render.h"
#include "screen.h"

bool running = true;

int main(int argc, char*  args[])
{
	Screen* screen = new Screen(640, 480);
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
		r.drawBoard(0,0,0,0);
		r.update();
	}	
	screen->close();
	return 0;
}
