#include "old.h"

#include <iostream>

Old::Old(const std::string& name) : Person(name, 90, 10, 90)
{
	std::cout << "Old: Hello! I am " << _name << " and I am finally old" << std::endl;
}

void Old::say() const
{
	std::cout << "Old: It is time to dye my hair violet!" << std::endl;
}

void Old::goFeedPegeons() const
{
	std::cout << "Old: Hello pigeons!" << std::endl;
}

Old::~Old()
{
	std::cout << "Old: Goodbuy! Have a nice party!" << std::endl;
}