#include "piece.h"
#include "pair.h"

class Move
{
	private:
		MoveType moveType;
		Pair squareSrc;
		Pair squareEnd;

	public:
		enum MoveType{
			MOVE,
			CAPTURE,
			K_CASTLE,
			Q_CASTLE
		};

		MoveType getMoveType();
};
