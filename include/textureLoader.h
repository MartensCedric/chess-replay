#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <string>
#include <SDL2/SDL.h>
#include <map>
#include "texture.h"
#include <iostream>

class TextureLoader
{
	SDL_Renderer* renderer;

	public:
	std::map<std::string, Texture*> textureMap;
	TextureLoader(SDL_Renderer* renderer);
	~TextureLoader();
	void loadTexture(const std::string& src);
	Texture* getTexture(const std::string& src) { 

	for(std::map<std::string, Texture*>::iterator it = textureMap.begin(); it != textureMap.end(); it++)
	{
	 	std::cout << "Key " << it->first << " - Value : " << it->second->width << " " << it->second->height << "\n" << std::endl;
	}
return textureMap[src]; }

	private:
};
#endif
