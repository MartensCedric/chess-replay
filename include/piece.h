#ifndef PIECE_H
#define PIECE_H
#include "piecetype.h"
class Piece
{
	PieceType pieceType;
	const bool white;
	public:
	Piece(bool white, PieceType pieceType):white(white){this->pieceType = pieceType;}
	PieceType getPieceType() const{return pieceType;}

	bool isWhite() const{return white;}
	bool isBlack() const{return !isWhite();}
};
#endif
