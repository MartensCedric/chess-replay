#include <string>
class Pair
{
	private:
		int rank;
		int file;
		void init(int rank, int file);

	public:
		std::string getNotation();
		int getRank();
		int getFile();
		Pair(int rank, int file);
		Pair(std::string notation);
};
