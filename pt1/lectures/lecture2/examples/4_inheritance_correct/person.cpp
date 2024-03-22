#include "person.h"

#include <iostream>

Person::Person(const std::string& name, uint money, uint energy, uint time) :
	_name(name), _money(money), _energy(energy), _time(time)
{
}

void Person::say() const
{
	std::cout << "I am a Person, let me say!" << std::endl;
}

void Person::act() const
{
	std::cout << "I can do smth!" << std::endl;
}

void Person::sayMoney() const
{
	std::cout << "I have " << _money << " money" << std::endl;
}

void Person::sayEnergy() const
{
	std::cout << "I have " << _energy << " energy" << std::endl;
}

void Person::sayTime() const
{
	std::cout << "I have " << _time << " time" << std::endl;
}