#pragma once
#include <string>

class Student
{
public:
	Student() = default;
	Student(const std::string& name, const std::string& secondName, double mark);

	void say() const;

	// надо как-то сравнивать студентов, чтобы найти нужного в хэш-таблице
	bool operator==(const Student& other) const;

	std::string getName() const;
	std::string getSecondName() const;
	double getAverageMark() const;

private:
	std::string _name;
	std::string _secondName;
	double _averageMark = 0;
};

class StudentsHash
{
public:
	size_t operator()(const Student& student) const;
};