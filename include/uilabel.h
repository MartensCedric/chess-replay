#ifndef UI_LABEL_H
#define UI_LABEL_H
#include "uielement.h"
#include <string>
class UiLabel : public UiElement
{
	std::string text;
	public:
	UiLabel(int x, int y, std::string text) : UiElement(x, y), text(text) {} 
	void draw() override;
	void setText(const std::string& text) {this->text = text; }
};
#endif
