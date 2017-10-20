#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Chess

#include <boost/test/unit_test.hpp>
#include "pgnparser.h"
#include "pair.h"
#include "pgn.h"
#include "board.h"
#include "piecetype.h"
#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <stdexcept>
#include "move.h"

std::string fileToString(std::string filePath)
{
	std::ifstream file;
	file.open(filePath, std::ios::in);
	PgnParser* parser = new PgnParser();

	if(!file.is_open())
	{	
		BOOST_FAIL("Could not open the PGN file to parse");
	}

	std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();

	return contents;
}

BOOST_AUTO_TEST_CASE(tagOK)
{
	PgnParser* parser = new PgnParser();
	std::string contents = fileToString("test/testmatches/tags.pgn");
	Pgn* pgnRes = parser->parse(contents);
	
	BOOST_CHECK_EQUAL(13, pgnRes->getMetadata().size());
}

BOOST_AUTO_TEST_CASE(tagNoSpaceKO)
{
	PgnParser* parser = new PgnParser();
	std::string contents = fileToString("test/testmatches/tags_no_spaces.pgn");
	BOOST_CHECK_THROW(parser->parse(contents), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(tagsNoQuoteKO)
{
	PgnParser* parser = new PgnParser();
	std::string contents = fileToString("test/testmatches/tags_no_quotes.pgn");
	BOOST_CHECK_THROW(parser->parse(contents), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(moveOK)
{
	Move* mvQcm = PgnParser::parseMove("0-0-0#");
	BOOST_CHECK_EQUAL(MoveType::Q_CASTLE, mvQcm->getMoveType());
	BOOST_CHECK_EQUAL(CheckType::CHECKMATE, mvQcm->getCheckType());
	delete mvQcm;

	Move* mvKc = PgnParser::parseMove("0-0+");
	BOOST_CHECK_EQUAL(MoveType::K_CASTLE, mvKc->getMoveType());
	BOOST_CHECK_EQUAL(CheckType::CHECK, mvKc->getCheckType());
	delete mvKc;

	Move* mvNormal = PgnParser::parseMove("e4");
	BOOST_CHECK_EQUAL(MoveType::MOVE, mvNormal->getMoveType());
	BOOST_CHECK_EQUAL(CheckType::NONE, mvNormal->getCheckType());
	BOOST_CHECK_EQUAL(4, mvNormal->getFinalPosition()->getFile());
	BOOST_CHECK_EQUAL(3, mvNormal->getFinalPosition()->getRank());
	delete mvNormal;
}

BOOST_AUTO_TEST_CASE(notationOK)
{
	Pair pe4("e4");
	BOOST_CHECK_EQUAL(3, pe4.getRank());
	BOOST_CHECK_EQUAL(4, pe4.getFile());
	BOOST_CHECK_EQUAL("e4", pe4.getNotation());
	
	Pair pg3("g3");
	BOOST_CHECK_EQUAL(2, pg3.getRank());
	BOOST_CHECK_EQUAL(6, pg3.getFile());
	BOOST_CHECK_EQUAL("g3", pg3.getNotation());
}

BOOST_AUTO_TEST_CASE(notationKO)
{
	BOOST_CHECK_THROW(new Pair("43"), std::runtime_error);
	BOOST_CHECK_THROW(new Pair("e4+"), std::invalid_argument);
	BOOST_CHECK_THROW(new Pair("i3"), std::runtime_error);
	BOOST_CHECK_THROW(new Pair("E4"), std::runtime_error); 	
}

BOOST_AUTO_TEST_CASE(castlingKO)
{
	Board b;
	BOOST_CHECK_THROW(b.castle(true, true), std::runtime_error);
}

//BOOST_AUTO_TEST_CASE(plyOK)
//{
//	PgnParser* parser = new PgnParser();
//	std::string contents = fileToString("test/testmatches/ply_only.pgn");
//	parser->parse(contents);
	//TODO
//	BOOST_CHECK_EQUAL(1,1);
//}
