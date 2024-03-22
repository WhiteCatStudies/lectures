#include <iostream>

#include "cat.h"

void play() 
{

	// Пример, показывающий вызов деструктора 
	// при выходе автоматического объекта из области видимости
	Cat cat = Cat("Automatic", "other", 10, 5, 5);
	cat.play();
}

int main()
{
	Cat defaultCat;	//создание объекта cat класса Cat с конструкторoм по умолчанию
	Cat cat = Cat("Pumpkin", "other", 10, 5, 5);
	std::getchar();

	Cat* dynamicCat = new Cat("Dynamic", "other", 10, 5, 5);
	dynamicCat->play();
	delete dynamicCat;
	std::getchar();

	cat.play();
	cat.play();
	cat.play();
	cat.play();
	cat.play();
	cat.play();
	std::getchar();

	play();
	std::getchar();
}
