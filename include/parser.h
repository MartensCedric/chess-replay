#ifndef PARSER_H
#define PARSER_H

#include "pgn.h"
#include <string>
#include <map>
#include <vector>

class PGNParser
{
	std::map<std::string, std::string> metadata;
	std::vector<Move> moves;
	
	
	public:
		PGN* parse(std::string& const contents) const;
};
#endif
