#ifndef STAGE_H
#define STAGE_H
#include "uielement.h"
#include <SDL2/SDL.h>
#include <vector>
class Stage
{
	int width, height;
	SDL_Renderer* renderer;
	std::vector<UiElement*> elements;
	public:
	Stage(int width, int height) : width(width), height(height) {}
	void add(UiElement* element) { elements.push_back(element); }
};
#endif
