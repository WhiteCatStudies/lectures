#include "exception_base.h"

#include <ctime>
#include <chrono>
#include <iostream>
#include <random>
#include <stdexcept>

static const int MAX_TIME = 9;

void goToInstitite()
{
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
	if (argc == 1)
	{
		maxTime = MAX_TIME;	
	}
	else
	{
		const std::string timeArg = std::string(argv[1]);

		try
		{
			// Функця std::stoi "бросает" 2 исключения: 
			// - std::invalid_argument, когда строку енвозможно преобразовать в число
			// - std::out_of_range, когда результат приводит 
			// к переполнению целевого типа (здесь - int)
			maxTime = std::stoi(timeArg);
		}
		catch (const std::exception& err)
		{
			// Нам важно знать, только было ли преобразование успешным. 
			// Если нет - не важно, по какой причине
			// Поэтому перехватывается исключение типа, от которого унаследованы
			// оба эти исключения (и все исключения стандартной библиотеки)
			std::cout << "Bad argument " << timeArg << ". Setting to default: "
				<< MAX_TIME << std::endl;

			maxTime = MAX_TIME;
		}
	}

	try
	{
		makeDesision(maxTime);
		std::cout << "I go to institite today!" << std::endl;
	}
	catch (const LateException& lateErr)
	//catch(StudentException err)
	{
		// Исключение может быть передано в catch-блок по ссылке
		// В противном случае, будет вызван конструктор копирования
		std::cout << lateErr.getReason() << ". What should I do?" << std::endl;
		processLate();
	}
	catch (const BadLuckException& badLuckErr)
	{
		std::cout << badLuckErr.getReason() << ". What should I do?" << std::endl;
		processBadLuck();
	}
	
}