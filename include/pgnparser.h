#ifndef PGN_PARSER_H
#define PGN_PARSER_H

#include "pgn.h"
#include <string>
#include <map>
#include <vector>
#include "move.h"
#include "ply.h"

class PgnParser
{
	std::map<std::string, std::string> metadata;
	std::vector<Move*> moves;
		
	public:
		~PgnParser();
		Pgn* parse(const std::string& contents);
		static Ply* parsePly(const std::string& rawPly);
		static Move* parseMove(const std::string& rawMove);
	private:
		void parseTag(const std::string& rawtag);
};
#endif
