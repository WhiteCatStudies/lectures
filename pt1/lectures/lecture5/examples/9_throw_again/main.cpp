#include <iostream>
#include <fstream>
#include <random>
#include <chrono>


void throwDice(int max)
{
	std::default_random_engine generator;
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(1, 6);
	const int dice = distribution(generator);
	std::cout << "The dice is " << dice << std::endl; 

	if (dice > max)
	{
		throw dice;
	}
}


void testLuck(int max)
{
	static std::ofstream log;
	// файл для записи с добавлением в конец
	log.open("badLuckLog.txt", std::ios_base::app);

	try
	{
		throwDice(max);
	}
	catch (int dice)
	{
		log << dice << std::endl;
		throw;
	}

	std::cout << "I am lucky this time!" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}

	int max = 0;
	try
	{
		max = std::stoi(argv[1]);
	}
	catch (const std::exception& err)
	{
		std::cout << "Invalid argument: " << argv[1] << std::endl;
		return 1; 
	}

	if (max < 1 || max > 6)
	{
		std::cout << "Dice should be between 1 and 6" << std::endl;
		return 1;
	}

	try
	{
		testLuck(max);
	}
	catch (int err)
	{
		std::cout << "It was a bad luck" << std::endl;
	}
}


