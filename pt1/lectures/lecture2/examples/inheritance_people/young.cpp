#include "young.h"

#include <iostream>

Young::Young(const std::string& name):
	_name(name)
{
	_money = 10;
	_energy = 90;
	_time = 90;

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

void Young::goStudy() const
{
	std::cout << "Young: I have slept just for 3 hours today! I can not study. Lets go party!" << std::endl;
}

void Young::sayMoney() const
{
	std::cout << "I have " << _money << " money" << std::endl;
}

void Young::sayEnergy() const
{
	std::cout << "I have " << _energy << " energy" << std::endl;
}

void Young::sayTime() const
{
	std::cout << "I have " << _time << " time" << std::endl;
}

Young::~Young()
{
	std::cout << "Young: Goodbuy! Have a nice party!" << std::endl;
}