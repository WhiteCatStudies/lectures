#include "cat.h"

#include <iostream>

const int Cat::_MIN = 0;

const int Cat::_MAX = 10;

 
Cat::Cat(const std::string& name, const std::string& breed,
	int mood, int energy, int hunger):
	_breed(breed), _name(name), _mood(_validate(mood))
{
	_mood = _validate(mood);
	_energy = _validate(energy);
	_hunger = _validate(hunger);

	std::cout << "-------------------------------" << std::endl;
	std::cout << "Hello! I am " << _name << " the cat" << std::endl;
}

Cat::Cat() 
{
	_mood = 0;
	_energy = 0;
	_hunger = 0;

	// _breed = std::string();
	// _name = std::string();

	std::cout << "Hello! I am a cat with no name " << std::endl;
}

void Cat::play() 
{
	if (!_energy) {
		std::cout << "I cant play! I am tired" << std::endl;
		_sleep();
		return;
	}

	if (_hunger >= _MAX) {
		std::cout << "I cant play! I am hungry" << std::endl;
		_meow();
		return;
	}

	std::cout << "Lets play!" << std::endl;

	_mood = _increase(_mood);
	_energy = _decrease(_energy);
	_hunger = _increase(_hunger);

	_meow();
}

void Cat::feed()
{
	if (!_hunger) {
		std::cout << "I am not hungry" << std::endl;
		return;
	}

	std::cout << "Yammy!" << std::endl;
	_hunger = _decrease(_hunger);
	_mood = _increase(_mood);
	_energy = _decrease(_energy);
	_sleep();
}

int Cat::getMood() const
{
	return _mood;
}

int Cat::getEnergy() const
{
	return _energy;
}

int Cat::getHunger() const
{
	return _hunger;
}

void Cat::_sleep()
{
	_energy = _increase(_energy);
	_hunger = _increase(_hunger);
	_mood = _decrease(_mood);

	if (!_mood) {
		std::cout << "I am sad. Play with me!" << std::endl;
	}
}

void Cat::_meow()
{
	std::cout << "Meow!" << std::endl;
}

inline int Cat::_increase(int val)
{
	return ++val > _MAX ? _MAX : val;
}

inline int Cat::_decrease(int val)
{
	return --val < 0 ? 0 : val;
}

int Cat::_validate(int val)
{
	if (val > _MAX) {
		return _MAX;
	}

	if (val < 0) {
		return 0;
	}

	return val;
}

Cat::~Cat()
{
	std::cout << "I am " << _name <<  "! I go to my new home! Goodbue!" << std::endl;
	std::cout << "-------------------------------" << std::endl;
}
