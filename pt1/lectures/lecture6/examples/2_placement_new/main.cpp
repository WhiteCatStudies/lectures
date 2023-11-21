/*
Пример на использование placement-new
Источники:
https://isocpp.org/wiki/faq/dtors#placement-new
https://en.cppreference.com/w/cpp/language/new#Placement_new
*/

#include <new> // placement-new
#include <iostream>
#include <iomanip> // std::boolalpha

#include "MyClass.h"


int main()
{
	{
		// Здесь могут проблемы с выравниванием.
		// sizeof возвращает размер объекта с учётом выравнивания, однако,
		// выравнивание массива memory и объектов MyClass
		// может не совпасть
		// alignas(T) char buf[sizeof(T)]; - должно решать проблему
		char memory[sizeof(MyClass)];

		MyClass* myPtr = new(memory) MyClass();
		getchar();

		std::cout << "Is placement pointer equal to the new-returned poiter?\n" <<
			std::boolalpha << (reinterpret_cast<char*>(myPtr) == memory) <<
			"\nIs this pointer equal to MyClass this pointer?\n" << 
			(myPtr->checkThis(myPtr)) << "\n" << std::endl;

		// Пожалуй, это единственный случай, 
		// когда необходимо вызвать деструктор в явном виде.
		// В неявном виде деструктор вызван не будет
		myPtr->~MyClass();
	}

	return 0;
}