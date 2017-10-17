#include "board.h"
#include "piece.h"
#include <stdexcept>
#include <iostream>
Board::Board()
{
	reset();
}

Piece* Board::getPieceAt(int rank, int file)
{
	ensureBoundaries(rank, file);
	return boardData[rank][file];
}

void Board::move(Piece* piece, int rankDest, int fileDest)
{
	ensureBoundaries(rank, file);

	Piece* p = boardData[rank][file];
	if(p != nullptr)
	{
		throw std::runtime_error("You can't move a piece to an occupied square!");
	}
	p = piece;
	piece = nullptr;
}

void Board::move(int rankSrc, int fileSrc, int rankDest, int fileDest)
{
	move(getPieceAt(rankSrc, fileSrc), rankDest, fileDest);
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

void Board::castle(bool white, bool kingside)
{
	int rank = white ? 0 : 7;
	
	int currFileRook = kingside ? 7 : 0;

	int newFileKing = kingside ? 6 : 2;
	int newFileRook = kingside ? 5 : 3;
	
	Piece* rook = getPieceAt(rank, currFileRook);
	Piece* king = getPieceAt(rank, 4);
	
	move(king, rank, newFileKing);
	move(rook, rank, newFileRook);	
}

Board::~Board()
{
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			delete boardData[i][j];
		}
	}
}
