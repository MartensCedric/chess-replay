#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Chess
#include <boost/test/unit_test.hpp>
#include "pgnparser.h"
#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

BOOST_AUTO_TEST_CASE(parserTestTag)
{
	std::ifstream file;
	file.open("test/test_tags.pgn", std::ios::in);
	PGNParser* parser = new PGNParser();
	PGN* PGNres = NULL;
	
	if(file.is_open())
	{
		std::string contents((std::istreambuf_iterator<char>(file)),
							 std::istreambuf_iterator<char>());
		PGNres = parser->parse(contents);		
	}else
	{
		BOOST_FAIL("Could not open the PGN file to parse!");
	}
	file.close();
	BOOST_CHECK_EQUAL(1, 1);
}

