#pragma once
#include <string>
#include <iostream>


class Student
{
public:
	Student() = default;
	Student(const std::string& name, const std::string& secondName, double mark);

	// friend std::ostream& operator<<(std::ostream& os, const Student& other);

	void say() const;
	std::string getName() const;
	std::string getSecondName() const;
	double getAverageMark() const;

private:
	std::string _name;
	std::string _secondName;
	double _averageMark = 0;
};

std::ostream& operator<<(std::ostream& os, const Student& student);
