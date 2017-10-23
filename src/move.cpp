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

bool Move::operator==(const Move& m)
{
	if(this == &m)
		return true;

	if(getCheckType() != m.getCheckType())
		return false;

	if(getMoveType() != m.getMoveType())
		return false;

	if(getFinalPosition() != m.getFinalPosition())
		return false;

	return true;
}

bool Move::operator!=(const Move& m)
{
	return !(*this == m);
}
