#include "textureLoader.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include "piece.h"

TextureLoader::TextureLoader(SDL_Renderer* renderer)
: renderer(renderer)
{
	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! %s\n", IMG_GetError());
	}
}

void TextureLoader::loadTexture(const std::string& src)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(src.c_str());

	if(loadedSurface == NULL)
	{
		printf("Unable to load image %s! %s", src.c_str(), IMG_GetError());
	}else{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);
		if(newTexture == NULL)
		{
			printf("Failed to load texture!\n");
		}else{
			Texture* t = new Texture(loadedSurface->w, loadedSurface->h);
			t->texture = newTexture;
			textureMap[src] = t;
		}
			SDL_FreeSurface(loadedSurface);
	}
}

std::string* TextureLoader::pieceToFilename(Piece* piece)
{
	std::string* filename = new std::string("");
	PieceType pt = piece->getPieceType();

	switch(pt)
	{
		case PieceType::PAWN:
			filename->append("pawn");
			break;
		
		case PieceType::BISHOP:
			filename->append("bishop");
			break;

		case PieceType::KNIGHT:
			filename->append("knight");
			break;

		case PieceType::ROOK:
			filename->append("rook");
			break;

		case PieceType::KING:
			filename->append("king");
			break;

		case PieceType::QUEEN:
			filename->append("queen");
			break;
	}

	filename->append("_");
	
	if(piece->isWhite())
	{
		filename->append("w");
	}else{
		filename->append("b");
	}

	filename->append(".png");
	return filename;
}

TextureLoader::~TextureLoader()
{
	for(std::map<std::string, Texture*>::iterator it = textureMap.begin(); it != textureMap.end(); it++)
	{
		SDL_DestroyTexture(it->second->texture);
	}
		
	textureMap.clear();
}
