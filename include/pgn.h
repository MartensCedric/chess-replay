#ifndef PGN_H
#define PGN_H

#include <string.h>
#include <map>
class Pgn
{
	std::map<std::string, std::string> metadata;

public:
	std::map<std::string, std::string>& getMetadata() { return metadata; }
	void setMetadata(std::map<std::string, std::string>& metadata) { this->metadata = metadata;};
	bool hasStr();
};
#endif
