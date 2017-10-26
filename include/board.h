#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "piecetype.h"
#include <string>
class Board
{
	Piece* boardData [8][8];
	public:
	Board();
	~Board();
	Piece* getPieceAt(int rank, int file);
	void move(Piece* piece, int rankDest, int fileDest);
	void move(int rankSrc, int fileSrc, int rankDest, int fileDest);
	void capture(Piece* attacker, Piece* defender);
	void castle(bool white, bool kingside);
	void reset();
	Piece* getBoardData() { return boardData[0][0]; }
	static std::string* pieceToFilename(Piece* piece);
	private:
	void ensureBoundaries(int rank, int file);
};
#endif
