#include "home.h"
#include <iostream>


Home::Home(size_t fridgeSize) : 
	_fridge(fridgeSize)
{
	const size_t foodSize = 4;
	std::string food[foodSize] = {"Cheese", "Ham", "Eggs", "Pelmeni"};

	const size_t size = (fridgeSize < foodSize) ? fridgeSize : foodSize;
	for (int i = 0; i < size; ++i)
	{
		_fridge.put(food[i]);
	}
}
