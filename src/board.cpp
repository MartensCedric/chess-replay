#include "board.h"
#include <stdexcept>
Board::Board()
{
	reset();
}

Piece* Board::getPieceAt(int rank, int file)
{
	ensureBoundaries(rank, file);
	return boardData[rank][file];
}

void Board::move(Piece* piece, int rank, int file)
{
	ensureBoundaries(rank, file);
	if(boardData[rank][file] != nullptr)
	{
		throw std::runtime_error("You can't move a piece to an occupied square!");
	}

}

void Board::ensureBoundaries(int rank, int file)
{
	if(rank >= 8 || rank < 0 
			|| file >= 8 || file < 0)
	{
		throw std::invalid_argument("Rank or file out of bounds");
	}
}

void Board::reset()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			boardData[i][j] = nullptr;
		}
	}

	for(int i = 0; i < 8; i++)
	{
		boardData[1][i] = new Piece(true, PieceType::PAWN);
		boardData[6][i] = new Piece(false, PieceType::PAWN);
	}

	bool isWhite = true;
	int rankPos = 0;
	for(int i = 0; i < 2; i++)
	{
		if(i != 0)
		{
			isWhite = false;
			rankPos = 7;
		}
		boardData[rankPos][0] = new Piece(isWhite, PieceType::ROOK);
		boardData[rankPos][7] = new Piece(isWhite, PieceType::ROOK);
		boardData[rankPos][1] = new Piece(isWhite, PieceType::KNIGHT);
		boardData[rankPos][6] = new Piece(isWhite, PieceType::KNIGHT);
		boardData[rankPos][2] = new Piece(isWhite, PieceType::BISHOP);
		boardData[rankPos][5] = new Piece(isWhite, PieceType::BISHOP);
		boardData[rankPos][3] = new Piece(isWhite, PieceType::QUEEN);
		boardData[rankPos][4] = new Piece(isWhite, PieceType::KING);
	}
}

Board::~Board()
{
	delete [] boardData;
}
