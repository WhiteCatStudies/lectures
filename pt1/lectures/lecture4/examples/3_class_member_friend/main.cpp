#include <iostream>

#include "home.h"


int main()
{
	std::cout << "Lets go home and put some food in our fridge" << std::endl;
	const size_t fridgeSize = 10;
	Home home(fridgeSize);
	std::getchar();
	
	FridgeRaider fridgeRaider("Wasia");
	fridgeRaider.raid(home);
}	