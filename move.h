#include "piece.h"
class Move
{
	private:
		MoveType moveType;

	public:
		enum MoveType{
			MOVE,
			CAPTURE,
			K_CASTLE,
			Q_CASTLE
		};

		MoveType getMoveType();
};
