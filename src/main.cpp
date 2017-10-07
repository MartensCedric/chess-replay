#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include "pair.h"
#include "render.h"
#include "screen.h"
#include "pgn.h"
#include "textureLoader.h"

const std::string PIECE_SHEET = "images/pieces/piece_sheet.png";

int main(int argc, char*  args[])
{

	bool running = true;

	Screen* screen = new Screen(800, 600);
	screen->createWindow();

	Render* render = new Render(screen->getWindow());
	TextureLoader* textureLoader = new TextureLoader(render->getRenderer());
	textureLoader->loadTexture(PIECE_SHEET);

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
		render->clear(0x00, 0x00, 0x00, 0xFF);
		render->drawBoard(56, 56, 544, 544);
		render->update();
	}
	
	screen->close();
	
	delete textureLoader;
	delete render;
	delete screen;
	
	return 0;
}
