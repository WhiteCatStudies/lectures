#include "adult.h"

#include <iostream>

Adult::Adult(const std::string& name, const std::string& work) :
	Person(name, 90, 90, 10), _work(work)
{
	std::cout << "Adult: Hello! I am " << _name << " and I am adult" << std::endl;
}

void Adult::say() const
{
	std::cout << "Adult: I will be paying my mortgage for 30 years" << std::endl;
}

void Adult::goWork() const
{
	std::cout << "Adult: Lets go write some code" << std::endl;
}

Adult::~Adult()
{
	std::cout << "Adult: Goodbuy! Have a nice party!" << std::endl;
}
