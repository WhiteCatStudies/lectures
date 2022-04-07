#include "dice.h"

#include <iostream>

const uint Dice::_MIN = 1;
const uint Dice::_MAX = 6;

Dice::Dice(uint val)
{
	if (val < _MIN || val > _MAX)
	{
		// при неудачной инициализации 
		// можно выбросить исключение из конструктора 
		throw DiceValException();
	}

	_val = val; 
}

Dice::Dice() : _val(0)
{
}

Dice::~Dice()
{
	// Не стоит генерировать исключения в деструкторах - 
	// деуструкторы автоматических объектов вызываются в неявной форме
	// при вызоде из области видимости, и такое исключение никогда не будет перехвачено

	// if (_val == 0)
	// {
	// 	std::cout << "Destructing default-constructed dice" << std::endl; 
	// }
	// else
	// {
	// 	std::cout << "Destructind dice" << std::endl;
	// }

	// throw DiceValException();
}