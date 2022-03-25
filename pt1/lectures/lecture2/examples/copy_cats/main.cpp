#include <iostream>
#include "cat.h"

// Передаём кота по значению 
void catFunc(Cat cat)
{
	std::cout << "Congrats! You've just copied your cat!" << std::endl; 
}

// Передаём кота по ссылке
void catRefFunc(const Cat& cat)
{
	std::cout << "It is the same cat" << std::endl; 
}

Cat catReturningFunc()
{
	Cat testCat = Cat("Test", "usual", 10, 20, 60);
	std::cout << "Take your cat back!" << std::endl;
	return testCat;
}

int main()
{

	Cat testCat = Cat("Test", "usual", 10, 20, 60);
	catFunc(testCat);
	//catRefFunc(testCat);
	//catReturningFunc();
	//Cat test = testCat;

	getchar();
}