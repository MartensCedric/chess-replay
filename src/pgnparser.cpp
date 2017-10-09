#include "pgnparser.h"
#include "pgn.h"
#include <iostream>
#include <stdexcept>

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
			extractTagInfo(bracketData);
		}

		if(*it == '1' && *(it + 1) == '.')
		{
			while(it != contents.end())
			{
				plyIndex++;
				it+=2;
				std::string::iterator plyBegin = it;
				while(it != contents.end() && *it != '.')
				{
					it++;
				}

				while(*it != ' ')
				{
					if(it == plyBegin)
					{
						throw std::runtime_error("Could not find boundaries for ply : " + plyIndex);
					}
					it--;
				}
				std::string::iterator plyEnd = --it;
				std::string rawPly(plyBegin, plyEnd);
				extractPlyInfo(rawPly, plyIndex);
			}
		}
	}
		Pgn* pgn = new Pgn();
		pgn->setMetadata(metadata);
		return pgn;
}
void PgnParser::extractTagInfo(std::string& rawTag)
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

void PgnParser::extractPlyInfo(std::string& rawPly, int plyIndex)
{
	//TODO
	std::cout << rawPly << " " << plyIndex << std::endl;
}

PgnParser::~PgnParser()
{
	delete moves;
}
