#include "fridge.h"
#include "myexcept.h"

#include <iostream>

Fridge getFridge(size_t size)
{
	// RVO - обязательна начиная с C++ 17
	return Fridge(size);
}

Fridge getFridgeNRVO(size_t size)
{
	// NRVO - не обязательна
	Fridge fridge(size);
	return fridge;
}

int main()
{
	// Ожидается вызов конструктора
	std::cout << "Waiting for constructor to be called" << std::endl;
	Fridge first(10); 
	std::getchar();

	// Ожидается вызов конструктора копирования
	std::cout << "Waiting for copy constructor to be called" << std::endl;
	Fridge second = first;
	std::getchar();

	// Ожидается вызов конструктора и два вызова конструктора перемещения
	// первый перемещает временный объект в возвращаемое значение (операнд return)
	// второй - перемещает возвращённый объект в third
	std::cout << "Testing mandatory RVO\nWaiting for 1 construction and 2 move constructions" << std::endl; 
	Fridge third = getFridge(20); 
	std::getchar();

	std::cout << "Testing non-mandatory NRVO" << std::endl;
	Fridge fifth = getFridgeNRVO(5);
	std::getchar(); 

	// Ожидается вызов оператора копирующего присваивания
	std::cout << "Waiting for copy assignment" << std::endl;
	second = third; 
	std::getchar();

	// Ожидается вызов конструктора и оператора перемещающего присваивания
	std::cout << "Waiting for construction and move asignment" << std::endl;  
	second = Fridge(15);
	std::getchar();

	// на практике все это можно увидеть, 
	// только если компилировать код с флагом -fno-elide-constructors,
	// который запрещает компилятору выполнять оптимизацию, 
	// известную как copy elision (пропуск копии). 
	// При RVO (return value optimization) вместо вызова конструктора копии 
	// или перемещения возвращаемый объект
	// создаётся напрямую на стеке вызывающей функции. Начиная с С++17 RVO обязательно

	// разный вывод при компиляции с флагом -fno-elide-constructors и без него
	// Вывод: конструкторы не должны иметь сторонних эффектов
	Fridge::printOpCount();
	std::getchar();

	// Другой пример обязательной оптимизации:
	// ожидается 1 вызов конструктора и 3 вызова перемещающего конструктора:
	// перемещение в операнд return, в промежуточный объект Fridge и в fourth
	// без -fno-elide-constructors только один вызов конструктора
	
	std::cout << "Testing mandatory copy elision when construction from rvalue" << std::endl;
	// 1 вызов конструктора, 3 вызова конструктора перемещения
	Fridge fourth(Fridge(getFridge(4)));
	std::getchar();

	std::cout << "Testing non-mandatory copy elision when throwing and catching exceptions" << std::endl;

	try
	{
		// возможен copy elision при перемещении/копировании в операнд throw
		throw MyException("This is fail");
	}
	catch(MyException err)
	{
		// возможен copy elision при передаче параметра catch по значению
		std::cout << err.reason() << std::endl;
	}
}