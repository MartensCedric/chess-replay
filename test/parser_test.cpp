#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Chess
#include <boost/test/unit_test.hpp>
#include "parser.h"
#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

BOOST_AUTO_TEST_CASE(parserTest)
{
	std::ifstream file;
	file.open("test/test_match_1.pgn", std::ios::in);
	if(file.is_open())
	{
		std::string contents((std::istreambuf_iterator<char>(file)),
							 std::istreambuf_iterator<char>());
		std::cout << contents << std::endl;
	}
	file.close();
	BOOST_CHECK_EQUAL(1, 1);
}

