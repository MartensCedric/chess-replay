#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "piecetype.h"
class Board
{
	Piece* boardData [8][8];
	public:
	Board();
	~Board();
	Piece* getPieceAt(int rank, int file);
	void move(Piece* piece, int rankDest, int fileDest);
	void capture(Piece* attacker, Piece* defender);
	void castle(bool white, bool kingside);
	private:
	void ensureBoundaries(int rank, int file);
};
#endif
