#include "pgnparser.h"
#include "pgn.h"
#include <iostream>

PGN* PGNParser::parse(std::string& contents)
{
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
	}
	
	for(std::map<std::string, std::string>::iterator it = metadata.begin(); it != metadata.end(); it++)
	{
		std::cout << (*it).first << " -> " << (*it).second << std::endl;	
	}
}

void PGNParser::extractTagInfo(std::string& rawTag)
{
	int spacePos = rawTag.find(" ");
	std::string key = rawTag.substr(0, spacePos);
	rawTag.erase(0, spacePos + 1);

	//TODO make sure there is 2 double quotes	
	std::string value = rawTag.substr(1, rawTag.length() - 2);
	this->metadata[key] = value;
}
