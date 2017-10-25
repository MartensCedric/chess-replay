#include "pgnparser.h"
#include "pgn.h"
#include <iostream>
#include <stdexcept>
#include <cctype>

//TODO add const iteration
Pgn* PgnParser::parse(std::string& contents)
{
	int plyIndex = 0;
	for(std::string::iterator it = contents.begin(); it != contents.end(); it++)
	{
		if(*it == '[')
		{
			std::string bracketData;
			while(it != contents.end() && *(it + 1) != ']')
			{
				it++;
				bracketData.append(1, *it);
			}
			parseTag(bracketData);
		}

		if(*it == '1' && *(it + 1) == '.')
		{
			it++;
			while(it != contents.end())
			{
				plyIndex++;
				it++;
				std::string::iterator plyBegin = it;

				while(it != contents.end() && *it != '.')
				{
					it++;
				}

				std::string::iterator plyEnd = it;
				std::string rawPly(plyBegin, plyEnd);
				if(it != contents.end())
				{
					std::size_t spacePos = rawPly.find_last_of(" ");
					if(spacePos == std::string::npos)
					{
						throw std::runtime_error("Could not parse ply : " + rawPly);
					}
					rawPly = rawPly.substr(0, spacePos);
				}
				parsePly(rawPly);
			}
		}
	}
	Pgn* pgn = new Pgn();
	pgn->setMetadata(metadata);
	return pgn;
}
void PgnParser::parseTag(std::string& rawTag)
{
	std::size_t spacePos = rawTag.find(" ");
	if(spacePos == std::string::npos)
	{
		throw std::runtime_error("There is no space delimiter between the key and value of the raw tag : " + rawTag);	
	}
	std::string key = rawTag.substr(0, spacePos);
	rawTag.erase(0, spacePos + 1);

	int quoteOcc = 0;
	for(int i = 0; i < rawTag.length(); i++)
	{
		if(rawTag[i] == '"')
		{
			quoteOcc++;
		}
	}

	if(quoteOcc != 2)
	{
		throw std::runtime_error("There is not exactly two quotes in the value tag : " + rawTag);		
	}
	std::string value = rawTag.substr(1, rawTag.length() - 2);
	this->metadata[key] = value;
}

Ply* PgnParser::parsePly(const std::string& rawPly)
{
	std::size_t spacePos = rawPly.find(" ");

	if(spacePos == std::string::npos)
	{
		throw std::runtime_error("No space seperating moves in this ply : " + rawPly);
	}
	Ply* ply = new Ply();
	ply->whiteMove = new Move(rawPly.substr(0, spacePos));
	ply->blackMove = new Move(rawPly.substr(spacePos + 1, rawPly.length() - 1));
	return ply;
}

Move* PgnParser::parseMove(const std::string& rawMove)
{
	Move* move = new Move();
	if(rawMove.substr(0, 5) == "0-0-0")
	{
		move->setMoveType(MoveType::Q_CASTLE);
	}else if(rawMove.substr(0, 3) == "0-0")
	{
		move->setMoveType(MoveType::K_CASTLE);
	}else if(rawMove.find("x") != std::string::npos)
	{
		move->setMoveType(MoveType::CAPTURE);
	}else{
		move->setMoveType(MoveType::MOVE);
	}

	char lastChar = rawMove[rawMove.length() - 1];
	if(lastChar == '+')
	{
		move->setCheckType(CheckType::CHECK);
	}else if(lastChar == '#'){
		move->setCheckType(CheckType::CHECKMATE);
	}else{
		move->setCheckType(CheckType::NONE);
	}

	if(move->getMoveType() == MoveType::MOVE || move->getMoveType() == MoveType::CAPTURE)
	{
		bool fileDigitFound = false;
		std::string* notation = nullptr;
		for(std::string::const_iterator it = rawMove.end(); it != rawMove.begin() && !fileDigitFound; it--)
		{
			if(isdigit(*it))
			{
				fileDigitFound = true;
				notation = new std::string(it - 1, it + 1);
			}
		}

		if(!fileDigitFound)
		{
			throw std::runtime_error("Could not find file digit in :" + rawMove);
		}
		move->setFinalPosition(new Pair(*notation));
	}
	return move;
}

PgnParser::~PgnParser()
{
	moves.clear();
}
