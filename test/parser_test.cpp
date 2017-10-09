#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Chess

#include <boost/test/unit_test.hpp>
#include "pgnparser.h"
#include "pgn.h"
#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <stdexcept>

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

BOOST_AUTO_TEST_CASE(plyOK)
{
	PgnParser* parser = new PgnParser();
	std::string contents = fileToString("test/testmatches/ply_only.pgn");
	parser->parse(contents);
	//TODO
	BOOST_CHECK_EQUAL(1,1);
}
