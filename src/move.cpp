#include "move.h"
#include "pair.h"
#include "pgnparser.h"

Move::Move()
{

}

Move::Move(const std::string& notation)
{
	Move* m = PgnParser::parseMove(notation);
	setMoveType(m->getMoveType());
	setCheckType(m->getCheckType());
	setFinalPosition(m->getFinalPosition());
	delete m;
}

Move::~Move()
{
}

bool operator==(Move m1, Move m2)
{
	if(&m1 == &m2)
		return true;

	if(m1.getCheckType() != m2.getCheckType())
		return false;

	if(m1.getMoveType() != m2.getMoveType())
		return false;

	if(m1.getFinalPosition() != m2.getFinalPosition())
		return false;

	return true;
}
