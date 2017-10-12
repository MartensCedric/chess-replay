#include "pair.h"
#include <string>
#include <stdexcept>

Pair::Pair(int rank, int file) 
	: rank(rank), file(file) 
{
	ensureValid();
}

Pair::Pair(const std::string& notation) 
	: rank(getRankFromNotation(notation)),
	file(getFileFromNotation(notation)) 
{
	ensureValid();
}

int Pair::getRank() const
{
	return this->rank;
}

int Pair::getFile() const
{
	return this->file;
}

std::string Pair::getNotation()
{
	return "";
}

void Pair::ensureValid() const
{
	if(rank < 0 || rank >= 8 ||
		file < 0 || file >= 8)
	{
				
	}
}

int Pair::getRankFromNotation(const std::string& notation)
{	
	if(notation.length() != 2)
	{
		throw std::invalid_argument("Invalid notation : " + notation);
	}

	return notation[1] - '1';
}

int Pair::getFileFromNotation(const std::string& notation)
{
	return notation[0] - 'a';
}
