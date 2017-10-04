#ifndef SCREEN_H
#define SCREEN_H
#include "SDL2/SDL.h"
class Screen
{

SDL_Window* window;
int width;
int height;

public:
Screen(int width, int height);
void createWindow();
void close();
SDL_Window* getWindow(){ return this->window; }
private:
	 
};
#endif
