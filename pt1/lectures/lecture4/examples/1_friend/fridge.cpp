#include "fridge.h"

#include <iostream>


Fridge::Fridge(size_t size)
{
	_food = new std::string[size];
	_size = size;
	_index = 0;
}

void Fridge::put(const std::string& food)
{
	if (_index >= (_size - 1))
	{
		std::cout << "The fridge is full!" << std::endl;
		return;
	}

	_food[_index] = food;
	++_index;
	std::cout << "The " << food << " is in the fridge now!" << std::endl;
}

std::string Fridge::get()
{
	if (_index == 0)
	{
		std::cout << "Sorry, no food (=" << std::endl;
		return std::string();
	}

	--_index;
	const std::string food = _food[_index];
	_food[_index] = std::string();
	return food;
}

Fridge::~Fridge()
{
	delete[] _food;
}