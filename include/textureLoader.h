#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <string>
#include <SDL2/SDL.h>
#include <map>
class TextureLoader
{
	std::map<std::string, SDL_Texture*> textureMap;
	SDL_Renderer* renderer;

	public:
	TextureLoader(SDL_Renderer* renderer);
	SDL_Texture* loadTexture(std::string& src);
	SDL_Texture* getTexture(std::string& src);

	private:
};
#endif
