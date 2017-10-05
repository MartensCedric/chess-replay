#ifndef PAIR_H
#define PAIR_H

#include <string>
class Pair
{
 	const int rank;
	const int file;

public:
	Pair(int rank, int file);
	Pair(const std::string& notation);

	std::string getNotation();
		
	int getRank() const;
	int getFile() const;

private:
	void ensureValid() const;

	static int getRankFromNotation(const std::string& notation);
	static int getFileFromNotation(const std::string& notation);
};
#endif
