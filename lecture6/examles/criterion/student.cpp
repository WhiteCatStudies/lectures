#include "student.hpp"

#include <iostream>
#include <functional>


Student::Student(const std::string& name, const std::string& secondName, 
	double mark):
	_name(name),
	_secondName(secondName),
	_averageMark(mark)
{}

void Student::say() const
{
	// Никакой необходимости использовать лямбду - абсолютно надуманный пример
	// Но иногда действительно надо
	[this](){ std::cout << "Hello, I am " << _name << " " << _secondName << '\n' <<
			  "I want to sleep" << std::endl;}();
}

std::string Student::getName() const
{
	return _name;
}

std::string Student::getSecondName() const
{
	return _secondName;
}

double Student::getAverageMark() const
{
	return _averageMark;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
	os << student.getName() << " " << student.getSecondName() << 
		": " << student.getAverageMark();
	return os;
}
