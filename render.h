#include <SDL2/SDL.h>
class Render
{
	private:
	SDL_Renderer* renderer = NULL;
	
	public:
	Render(SDL_Window* window);
	void drawBoard(int x, int y, int w, int h);
	void update();
};
