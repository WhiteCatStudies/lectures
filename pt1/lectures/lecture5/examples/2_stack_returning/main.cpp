#include "myclass.h"

#include <iostream>

void funcD()
{
	std::cout << "Entering funcD" << std::endl; 
	MyClass myClassA('D');
	std::cout << "Returning from funcD" << std::endl;
}

void funcC()
{
	std::cout << "Entering funcC" << std::endl; 
	MyClass myClassA('C');
	funcD();
	std::cout << "Returning from funcC" << std::endl;
}

void funcB()
{
	std::cout << "Entering funcB" << std::endl; 
	MyClass myClassB('B');
	funcC();
	std::cout << "Returning from funcB" << std::endl;
}

void funcA()
{
	std::cout << "Entering funcA" << std::endl; 
	MyClass myClassA('A');
	funcB();
	std::cout << "Returning from funcA" << std::endl;
}

int main()
{
	funcA();
}