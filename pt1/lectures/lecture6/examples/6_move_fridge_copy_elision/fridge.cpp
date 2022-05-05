#include "fridge.h"

#include <sstream>

size_t Fridge::_copyCount = 0;
size_t Fridge::_moveCount = 0; 

Fridge::Fridge(size_t size)
{
	std::cout << "Constructor of fridge size " << size <<std::endl;
	_food = new std::string[size];
	_size = size;
	_index = 0;
}

Fridge::Fridge(const Fridge& other)
{
	std::cout << "Copy construction from frindge size " << other._size << std::endl;
	_size = other._size;
	_index = other._index;

	_food = new std::string[_size];

	for (int i = 0; i <= _index; ++i)
	{
		_food[i] = other._food[i];
	}

	++_copyCount;
}

Fridge::Fridge(Fridge&& other)
{
	std::cout << "Move constructor from fridge size " << other._size << std::endl;
	_size = other._size;
	_index = other._index;

	// "забираем" указатель у другого объекта и даём ему взамен нулевой указатель
	_food = other._food;

	other._food = nullptr;
	other._size = 0;
	other._index = 0;

	++_moveCount;
}

Fridge& Fridge::operator=(const Fridge& other)
{
	std::cout << "Copy assignment of fridge size " << other._size <<
		" to fridge size " << _size << std::endl;

	_size = other._size;
	_index = other._index;
	// удаляем старый массив и выделяем новый другого размера
	// стоило бы выделять новый массив только в случае неравенства размеров 
	delete[] _food;
	_food = new std::string[_size];

	for (size_t i = 0; i < _size; ++i)
	{
		_food[i] = other._food[i]; 
	}

	++_copyCount;

	return *this; 
};


Fridge& Fridge::operator=(Fridge&& other)
{
	std::cout << "Move assignment of fridge size " << other._size << 
		" to fridge size " << _size << std::endl;

	delete[] _food;
	_food = other._food;
	_size = other._size;
	_index = other._index;

	other._food = nullptr;
	other._size = 0;
	other._index = 0;

	++_moveCount;
	return *this;
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
	std::cout << "Take your " << food << std::endl; 	
	return food;
}

void Fridge::printOpCount()
{
	std::cout << "Copied " << _copyCount << " times. Moved " << _moveCount << 
		" times" << std::endl;
}

Fridge::~Fridge()
{
	if (_food != nullptr)
	{
		std::cout << "Destructor of fridge size " << 
			_size << std::endl;
		delete[] _food;
	}
}
