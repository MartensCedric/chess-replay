#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include "texture.h"

class Render
{
	private:
	SDL_Renderer* renderer = NULL;
	
	public:
	Render(SDL_Window* window);
	void drawBoard(int x, int y, int w, int h);
	void render(Texture* texture, int x, int y);
	void render(Texture* texture, int x, int y, SDL_Rect* clip);
	void clear(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void clear();
	void update();
	SDL_Renderer* getRenderer() const { return renderer; }
};
#endif
