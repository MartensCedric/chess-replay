#include "textureLoader.h"
#include <iostream>
#include <SDL2/SDL_image.h>

TextureLoader::TextureLoader(SDL_Renderer* renderer)
: renderer(renderer)
{
	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! %s\n", IMG_GetError());
	}
}

void TextureLoader::loadTexture(std::string src)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(src.c_str());

	if(loadedSurface == NULL)
	{
		printf("Unable to load image %s! %s", src.c_str(), IMG_GetError());
	}else{

		newTexture = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);
		SDL_FreeSurface(loadedSurface);
		if(newTexture == NULL)
		{
			printf("Failed to load texture!\n");
		}else{
			Texture t;
			t.texture = newTexture;
			t.width = 400;
			t.height = 400;
			textureMap[src] = &t;
		}	
	}
}

Texture* TextureLoader::getTexture(std::string src)
{
	return textureMap[src];
}

TextureLoader::~TextureLoader()
{
	for(std::map<std::string, Texture*>::iterator it = textureMap.begin(); it != textureMap.end(); it++)
	{
		SDL_DestroyTexture(it->second->texture);
	}
		
	textureMap.clear();
}
