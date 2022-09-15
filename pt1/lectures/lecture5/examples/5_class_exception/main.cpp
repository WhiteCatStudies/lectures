/*
Перехват исключений пользовательского типа
с использованием иерархии классов
*/


#include <ctime>
#include <chrono>
#include <iostream>
#include <random>

#include "exception.h"


static const int MAX_TIME = 15;

void goToInstitite()
{
	std::cout << "I go to institite today!" << std::endl;
}

void makeDesision()
{
	// Смотрим, который час. Если уже слишком поздно,
	// в институт ехать нет смысла 
	const std::time_t time = std::time(nullptr);
	const std::tm* localTime = std::localtime(&time);
	const int hour = localTime->tm_hour;

	if (hour > MAX_TIME)
	{
		throw StudentException("It is too late: " + std::to_string(hour));	
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
		throw(StudentException("It is a bad luck"));
	}

	goToInstitite();
}

int main()
{
	try
	{
		makeDesision();
	}
	catch(const StudentException& err)
	//catch(StudentException err)
	{
		// Исключение может быть передано в catch-блок по ссылке
		// В противном случае, будет вызван конструктор копирования
		std::cout << "I wont go to the institute because " << 
			err.getReason() << std::endl;
	}
}