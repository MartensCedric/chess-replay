#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H
class UiElement
{
	int x, y;

	public:
	UiElement(int x, int y) : x(x), y(y){}
	void virtual draw() = 0;

	int getX() const { return x; }
	void setX(int x) {this->x = x; }
	
	int getY() const { return y; }
	void setY(int y) {this->y = y; }
};
#endif
