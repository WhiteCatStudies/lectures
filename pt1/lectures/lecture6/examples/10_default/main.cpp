#include "cat.h"

#include <iostream>

int main()
{
	// инициализация в конструкторе имеет приоритет над 
	// инициализацией при объявлении класса (in-class initialization)
	Cat cat("Wasia", "Other", 3, 3, 10);
	std::cout << cat << std::endl;
	std::getchar();

	// Другие члены данных класса инициализированы in-class
	Cat namedCat("Kot");
	std::cout << namedCat << std::endl;
	std::getchar();

	// _name инициализирован конструктором по умолчанию std::string
	Cat defaultCat;
	std::cout << defaultCat << std::endl;
}