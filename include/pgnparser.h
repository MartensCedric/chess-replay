#ifndef PGN_PARSER_H
#define PGN_PARSER_H

#include "pgn.h"
#include <string>
#include <map>
#include <vector>
#include "move.h"

class PgnParser
{
	std::map<std::string, std::string> metadata;
	std::vector<Move>* moves;
		
	public:
		~PgnParser();
		Pgn* parse(std::string& contents);
	private:
		void extractTagInfo(std::string& rawtag);
		void extractPlyInfo(std::string& rawPly, int plyIndex);
};
#endif
