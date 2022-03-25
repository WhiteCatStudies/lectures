#include "dice.h"

#include <iostream>

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}

	// здесь должна быть обработка исключений для std::stoi
	const int val = std::stoi(argv[1]);

	Dice dice;

	try
	{
		dice = Dice(val);
		std::cout << "The dice is " << val << std::endl;
	}
	catch (const DiceValException& err)
	{
		std::cout << "Invalid dice value: " << val << std::endl; 
	}

}