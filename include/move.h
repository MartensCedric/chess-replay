#ifndef MOVE_H
#define MOVE_H

#include "piece.h"
#include "pair.h"
#include "movetype.h"
#include "checktype.h"
#include <string>
class Move
{
	std::string comments;

	//Pair pieceInitPos;
	//Pair pieceFinalPos;
	MoveType moveType;
	CheckType checkType;
	uint8_t nag;	

	public:
		Move();
		void setMoveType(MoveType moveType){ this->moveType = moveType; }
		MoveType getMoveType(){ return moveType; }

		void setCheckType(CheckType checkType){ this->checkType = checkType; }
		CheckType getCheckType(){ return checkType; }
	
	private:
	
};
#endif
