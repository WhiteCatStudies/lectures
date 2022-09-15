#include "exception_base.h"

#include <ctime>
#include <chrono>
#include <iostream>
#include <random>

static const int MAX_TIME = 9;

void goToInstitite()
{

	std::cout << "I go to institite today!" << std::endl;	
}

void processLate()
{
	std::cout << "I should get a taxi, this must be faster" << std::endl;
}

void processBadLuck()
{
	std::cout << "Bad luck is a nonsence!" << std::endl;
}

void makeDesision(int maxTime)
{
	// Смотрим, который час. Если уже слишком поздно,
	// в институт ехать нет смысла 
	const std::time_t time = std::time(nullptr);
	const std::tm* localTime = std::localtime(&time);
	const int hour = localTime->tm_hour;

	if (hour > maxTime)
	{
		throw LateException();	
	}

	// Проспать не получилось. Придётся бросaть кости
	std::default_random_engine generator;
	generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(1, 6);
	const int dice = distribution(generator);
	std::cout << "The dice is " << dice << std::endl; 

	if (dice > 3)
	{
		// Не судьба
		throw BadLuckException();
	}

	goToInstitite();
}

int main(int argc, char* argv[])
{
	unsigned int maxTime = 0; 
	if (argc != 2)
	{
		std::cout << "Invalid argumemnts" << std::endl;
		// exit(1);
		return 1;
	}

	try
	{
		const std::string timeArg = std::string(argv[1]);
		maxTime = std::stoi(timeArg);
		makeDesision(maxTime);
	}
	catch (const LateException& lateErr)
	{
		std::cout << lateErr.getReason() << ". What should I do?" << std::endl;
		processLate();
	}
	catch (const BadLuckException& badLuckErr)
	{
		std::cout << badLuckErr.getReason() << ". What should I do?" << std::endl;
		processBadLuck();
	}
	catch (...)
	{
		// вместо std::exception ловим вообще все исключения
		std::cout << "Bad arguments " << std::endl;
	}

	return 0;
}