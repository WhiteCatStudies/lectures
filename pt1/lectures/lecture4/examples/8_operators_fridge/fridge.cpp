#include "fridge.h"

#include <sstream>

Fridge::Fridge(size_t size)
{
	std::cout << "Fridge: allocating memory for fridge size " << size <<std::endl;
	_food = new std::string[size];
	_size = size;
	_index = 0;
}

Fridge::Fridge(const Fridge& other)
{
	std::cout << "Fridge: allocating memory for copy" <<std::endl;
	_size = other._size;
	_index = other._index;

	_food = new std::string[_size];

	for (int i = 0; i <= _index; ++i)
	{
		_food[i] = other._food[i];
	}
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

	return *this; 
};

std::string& Fridge::operator[](int index)
{
	std::cout << "Calling indexing operator" << std::endl;
	return _food[index];
}

std::string Fridge::operator()()
{
	std::stringstream stream; 
	stream << "Whats in the fridge?\n";
	for (int i = 0; i < _index; ++i)
	{
		const std::string food = _food[i]; 
		stream << food << ";\n";
	}

	return stream.str();
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

Fridge::~Fridge()
{
	if (_food != nullptr)
	{
		std::cout << "Fridge: freeing memory of fridge size " << 
			_size << std::endl;
		delete[] _food;
	}
}

std::istream& operator>>(std::istream& is, Fridge& fridge)
{
	std::string item;
	is >> item;
	fridge.put(item);
	return is;   
}