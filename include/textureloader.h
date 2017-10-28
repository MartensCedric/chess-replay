#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <string>
#include <SDL2/SDL.h>
#include <map>
#include "texture.h"
#include <iostream>
#include "piece.h"
#include "piecetype.h"

class TextureLoader
{
	SDL_Renderer* renderer;
	std::map<std::string, Texture*> textureMap;
	public:
	TextureLoader(SDL_Renderer* renderer);
	~TextureLoader();
	void loadTexture(const std::string& src);
	Texture* getTexture(const std::string& src) { return textureMap[src]; }
	static std::string* pieceToFilename(Piece* piece);

	private:
};
#endif
