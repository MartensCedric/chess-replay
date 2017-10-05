#ifndef PGN_H
#define PGN_H

#include <string.h>
#include <map>
class PGN
{
	std::map<std::string, std::string> metadata;

public:
	std::map<std::string, std::string>& getMetadata() { return metadata; }
	bool hasSTR();
};
#endif
