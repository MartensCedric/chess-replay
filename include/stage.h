#ifndef STAGE_H
#define STAGE_H
#include "uielement.h"
#include <SDL2/SDL>
class Stage
{
	SDL_Renderer* renderer;
	std::vector<UiElement> elements;
	public:
	Stage(SDL_Renderer* renderer);
	void draw();
	void add(UiElement element;) { elements.push_back(element); }
};
#endif
