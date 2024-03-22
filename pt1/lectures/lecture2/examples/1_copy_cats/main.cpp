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
	Cat testCat = Cat("Returned", "usual", 10, 20, 60);
	std::cout << "Take your cat back!" << std::endl;
	return testCat;
}

int main()
{

	Cat testCat = Cat("Test", "usual", 10, 20, 60);
	std::getchar();

	std::cout << "Make a copy of cat" << std::endl;
	Cat newCat = testCat;
	std::getchar();

	std::cout << "Pass the cat by value" << std::endl;
	catFunc(testCat);
	std::getchar();

	std::cout << "Pass the cat by reference" << std::endl;
	catRefFunc(testCat);
	std::getchar();

	// Оптимизация: вызова конструктора копирования и деструктора копии не будет 
	std::cout << "Return cat from a function" << std::endl;
	Cat returnedCat = catReturningFunc();

	std::getchar();
}