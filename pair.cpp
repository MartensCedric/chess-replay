#include "pair.h"
#include <string>
#include <exception>

Pair::Pair(int rank, int file)
{
	init(rank, file);
}

Pair::Pair(std::string notation) 
{
	if(notation.length() != 2)
	{
		//throw std::exception("Notation does not have two values");
	}

	int file = notation[0] - 'a';
	int rank = notation[1] - '1';
	init(rank, file);
}

int Pair::getRank()
{
	return this->rank;
}

int Pair::getFile()
{
	return this->file;
}

std::string Pair::getNotation()
{
	return "";
}

void Pair::init(int rank, int file)
{
	if(rank < 0 || rank >= 8 ||
			file < 0 || file >= 8)
	{
		//throw std::exception("Values out of chess board");
	}

	this->rank = rank;
	this->file = file;
}
