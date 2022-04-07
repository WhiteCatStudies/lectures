#include <iostream>

int main()
{
	std::cout << "Lets throw some exceptions!" << std::endl;
	throw 99;
	std::cout << "I will never print anything(=" << std::endl;
}