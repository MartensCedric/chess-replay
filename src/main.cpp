#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "pair.h"
#include "render.h"
#include "screen.h"
#include "pgn.h"
#include "textureLoader.h"
#include <SDL2/SDL_image.h>
const std::string SPR_KING_W = "images/pieces/king_w.png";

int main(int argc, char* args[])
{

	bool running = true;
	Board* board = new Board();
	Screen* screen = new Screen(800, 600);
	screen->createWindow();

	Render* render = new Render(screen->getWindow());
	TextureLoader* textureLoader = new TextureLoader(render->getRenderer());
	textureLoader->loadTexture(SPR_KING_W);
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
		render->renderTiles(56, 56, 544, 544);
		render->renderPieces(board);
		render->update();
	}
	
	screen->close();
	
	delete textureLoader;
	delete render;
	delete screen;
	
	return 0;
}

