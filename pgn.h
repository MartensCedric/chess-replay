#ifndef PGN_H
#define PGN_H

#include <string.h>
class PGN
{
	std::map<std::string, std::string> metadata;

public:
	const std::map<std::string, std::string>& getMetadata() const;

}
#endif
