#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <string>
#include <SDL2/SDL.h>
#include <map>
#include "texture.h"

class TextureLoader
{
	std::map<std::string, Texture*> textureMap;
	SDL_Renderer* renderer;

	public:
	TextureLoader(SDL_Renderer* renderer);
	~TextureLoader();
	void loadTexture(std::string src);
	Texture* getTexture(std::string src);

	private:
};
#endif
