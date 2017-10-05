#include "pgn.h"

/**
	Returns true if the PGN object has information on the Seven Tag Roaster (STR), returns false otherwise.
*/
bool PGN::hasSTR()
{
	std::string tags[] = {"Event", "Site", "Date", "Round", "White", "Black", "Result"};
	
	for(int i = 0; i < (sizeof(tags)/sizeof(tags[0])); i++)
	{	
		if(this->metadata.count(tags[i]) == 0)
		{
			printf("%s\n", tags[i]);	
			return false;
		}
	}
	
	return true;
}
