#include "student.h"

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
	std::cout << "Hello, I am " << _name << " " << _secondName << '\n' <<
		"I want to sleep" << std::endl; 
}

bool Student::operator==(const Student& other) const
{
	return (_name == other._name) && (_secondName == other._secondName) && 
		(_averageMark == other._averageMark);
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

size_t StudentsHash::operator()(const Student& student) const
{
	// скорее всего, это не очень хорошая хэш-функция
	return std::hash<std::string>()(student.getName()) + 
		std::hash<std::string>()(student.getSecondName()) +
		std::hash<double>()(student.getAverageMark());
}