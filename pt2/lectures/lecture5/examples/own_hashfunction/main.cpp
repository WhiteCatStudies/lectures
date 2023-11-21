#include "student.h"

#include <iostream>
#include <unordered_set>

int main()
{
	const auto wasia = Student("Wasiliy", "Kotikoff", 4.9);
	wasia.say();

	const auto masha = Student("Masha", "Umnjashina", 4.9);
	masha.say();

	std::unordered_set<Student, StudentsHash> students = {wasia, masha};

	const auto it = students.find(masha);
	if (it == students.end())
	{
		std::cout << "No Masha (=" << std::endl;
	}
	else
	{
		std::cout << "Masha is found!" << std::endl;
		it->say();
	}
}
