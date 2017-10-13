#include "board.h"
#include <stdexcept>
Board::Board()
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

Board::~Board()
{
	delete [] boardData;
}
