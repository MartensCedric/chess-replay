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

Render* render = NULL;
TextureLoader* textureLoader = NULL;

//Move in textureLoader
void loadTexture(const std::string& contents)
{
	SDL_Texture* texture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(SPR_KING_W.c_str());
	texture = SDL_CreateTextureFromSurface(render->getRenderer(), loadedSurface);
	Texture t(loadedSurface->w, loadedSurface->h);
	t.texture = texture;
	
	SDL_FreeSurface(loadedSurface);	
 	textureLoader->textureMap[SPR_KING_W] = &t;
}

int main(int argc, char* args[])
{

	bool running = true;

	Screen* screen = new Screen(800, 600);
	screen->createWindow();

	render = new Render(screen->getWindow());
	textureLoader = new TextureLoader(render->getRenderer());
	//textureLoader->loadTexture(SPR_KING_W);
	loadTexture(SPR_KING_W);
/*	SDL_Texture* texture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(SPR_KING_W.c_str());
	texture = SDL_CreateTextureFromSurface(render->getRenderer(), loadedSurface);
	Texture t(loadedSurface->w, loadedSurface->h);
	t.texture = texture;
	
	SDL_FreeSurface(loadedSurface);	
 	textureLoader->textureMap[SPR_KING_W] = &t;
*/
	Texture* tex = textureLoader->getTexture(SPR_KING_W);
	std::cout << tex->width << "\t" << tex->height << std::endl;
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
		render->render(tex, 200, 300, 72, 72);
		render->update();
	}
	
	screen->close();
	
	delete textureLoader;
	delete render;
	delete screen;
	
	return 0;
}

