#ifndef UI_LABEL_H
#define UI_LABEL_H
#include "uielement.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "texture.h"

class UiLabel : public UiElement
{
	std::string text;
	TTF_Font* font;
	SDL_Color color = { 255, 255, 255 };
	Texture* texture = nullptr;
	public:
	UiLabel(int x, int y, std::string text) : UiElement(x, y), text(text) {} 
	void draw(SDL_Renderer* renderer) override;
	void setText(const std::string& text) {this->text = text; }
	void setFont(TTF_Font* font) { this->font = font; }
	void applyChanges();
};
#endif
