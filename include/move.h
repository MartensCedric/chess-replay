#include "piece.h"
#include "pair.h"
#include "movetype.h"
#include "checktype.h"
#include <string>

class Move
{
	std::string comments;

	Pair pieceInitPos;
	Pair pieceFinalPos;
	MoveType moveType;
	CheckType checkType;
	uint8_t nag;	

	public:
		MoveType getMoveType();
	
	private:
	
};
