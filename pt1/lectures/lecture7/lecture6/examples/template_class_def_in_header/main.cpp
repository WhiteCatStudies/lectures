#include <string>
#include <vector>

#include "mypair.h"

int main()
{
	MyPair<std::string, int> mark("Wasia", 5);
	std::cout << mark << std::endl; 
	MyPair<std::string, int> newMark = MyPair<std::string, int>::makePair("Kolia", 4);

	MyPair<double, double> scores(2.5, 10.7); 
	std::cout << scores << std::endl;

	MyPair<> money(10, 50);
	std::cout << money << std::endl;

	MyPair<std::string, std::vector<int>> grades("Anna", std::vector<int>({3, 4, 5}));
}