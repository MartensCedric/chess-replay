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

	MoveType moveType;
	CheckType checkType;
	uint8_t nag;	
	Pair* finalPos = nullptr;
	public:
		Move();
		Move(const std::string& notation);
		~Move();
		void setMoveType(MoveType moveType){ this->moveType = moveType; }
		MoveType getMoveType() const { return moveType; }

		void setCheckType(CheckType checkType){ this->checkType = checkType; }
		CheckType getCheckType() const { return checkType; }
		
		void setFinalPosition(Pair* finalPos) { this->finalPos = finalPos; }
		Pair* getFinalPosition() const { return finalPos; }	
	
		bool operator==(const Move& m);
		bool operator!=(const Move&m);
	private:
	
};
#endif
