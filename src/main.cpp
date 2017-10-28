#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "pair.h"
#include "render.h"
#include "screen.h"
#include "pgn.h"
#include "textureloader.h"
#include <SDL2/SDL_image.h>

const std::string IMG_PATH = "images/pieces/";

int main(int argc, char* args[])
{
	bool running = true;
	Board* board = new Board();
	Screen* screen = new Screen(800, 600);
	screen->createWindow();

	Render* render = new Render(screen->getWindow());
	TextureLoader* textureLoader = new TextureLoader(render->getRenderer());
	textureLoader->loadTexture(IMG_PATH + "pawn_w.png");
	textureLoader->loadTexture(IMG_PATH + "pawn_b.png");
	textureLoader->loadTexture(IMG_PATH + "knight_w.png");
	textureLoader->loadTexture(IMG_PATH + "knight_b.png");
	textureLoader->loadTexture(IMG_PATH + "rook_w.png");
	textureLoader->loadTexture(IMG_PATH + "rook_b.png");
	textureLoader->loadTexture(IMG_PATH + "bishop_w.png");
	textureLoader->loadTexture(IMG_PATH + "bishop_b.png");
	textureLoader->loadTexture(IMG_PATH + "queen_w.png");
	textureLoader->loadTexture(IMG_PATH + "queen_b.png");
	textureLoader->loadTexture(IMG_PATH + "king_w.png");
	textureLoader->loadTexture(IMG_PATH + "king_b.png");
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
		render->renderPieces(board, textureLoader);
		render->update();
	}

	screen->close();

	delete textureLoader;
	delete render;
	delete screen;

	return 0;
}

