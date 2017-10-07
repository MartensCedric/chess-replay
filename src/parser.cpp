#include "parser.h"
#include "pgn.h"
#include <iostream>

PGN* PGNParser::parse(std::string& contents) const
{
	for(std::string::iterator it = contents.begin(); it != contents.end(); it++)
	{
		std::cout << *it;		
	}
}
