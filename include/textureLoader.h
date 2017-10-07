#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <string>
#include <SDL2/SDL.h>
#include <map>
#include "texture.h"

class TextureLoader
{
	SDL_Renderer* renderer;

	public:
	std::map<std::string, Texture*> textureMap;
	TextureLoader(SDL_Renderer* renderer);
	~TextureLoader();
	void loadTexture(const std::string& src);
	Texture* getTexture(const std::string& src) { return textureMap[src]; }

	private:
};
#endif
