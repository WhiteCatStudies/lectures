#include "old.h"

#include <iostream>

Old::Old(const std::string& name) :
	_name(name)
{
	_money = 90;
	_energy = 10;
	_time = 90;

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

void Old::sayMoney() const
{
	std::cout << "I have " << _money << " money" << std::endl;
}

void Old::sayEnergy() const
{
	std::cout << "I have " << _energy << " energy" << std::endl;
}

void Old::sayTime() const
{
	std::cout << "I have " << _time << " time" << std::endl;
}

Old::~Old()
{
	std::cout << "Old: Goodbuy! Have a nice party!" << std::endl;
}