#include "adult.h"

#include <iostream>

Adult::Adult(const std::string& name, const std::string& work) :
	_name(name), _work(work)
{
	_money = 90;
	_energy = 90;
	_time = 10;

	std::cout << "Adult: Hello! I am " << _name << " and I am adult" << std::endl;
}

void Adult::say() const
{
	std::cout << "Adult: I will be paying my mortgage for 30 years" << std::endl;
}

void Adult::act() const
{
	std::cout << "Adult: Lets go write some code" << std::endl;
}

void Adult::sayMoney() const
{
	std::cout << "I have " << _money << " money" << std::endl;
}

void Adult::sayEnergy() const
{
	std::cout << "I have " << _energy << " energy" << std::endl;
}

void Adult::sayTime() const
{
	std::cout << "I have " << _time << " time" << std::endl;
}

Adult::~Adult()
{
	std::cout << "Adult: Goodbuy! Have a nice party!" << std::endl;
}