#include "young.h"

#include <iostream>

Young::Young(const std::string& name) :
	Person(name, 10, 90, 90 )
{
	std::cout << "Young: Hello! I am " << _name << " and I am young" << std::endl;
}

void Young::say() const
{
	std::cout << "Young: Lets go party all hight!" << std::endl;
}

void Young::saySmthCool() const
{
	std::cout << "Young: *Says something. No one above 15 understands a word*" << std::endl;
}

void Young::act() const
{
	std::cout << "Young: I have slept just for 3 hours today! I can not study. Lets go party!" << std::endl;
}

Young::~Young()
{
	std::cout << "Young: Goodbuy! Have a nice party!" << std::endl;
}