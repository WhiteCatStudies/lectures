#include "a.h"

#include <iostream>

A::A()
{
	std::cout << "Construction of A" << std::endl;
}

A::~A()
{
	std::cout << "Destruction of A" << std::endl;
}