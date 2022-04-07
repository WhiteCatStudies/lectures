#include "myclass.h"

#include <iostream>

MyClass::MyClass(char name): _name(name)
{
	std::cout << "Construction of " << _name << std::endl;
}

MyClass::~MyClass()
{
	std::cout << "Destruction of " << _name << std::endl; 
}