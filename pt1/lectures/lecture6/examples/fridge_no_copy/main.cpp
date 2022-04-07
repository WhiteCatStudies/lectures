#include "fridge.h"

#include <utility>
#include <iostream>

struct Test
{
	static void foo(int x)
	{
		std::cout << "I am int param overload" << std::endl;
	}

	// запрещает неявное преобразование типов при передаче параметров в foo
	// если не удалить эту перегрузку, foo(int) будет принимать и int, 
	// и double ((конвертируя его в int)
	//static void foo(double x) = delete;
};

int main()
{
	// не компилируется, если foo(double) удалена
	Test::foo(2.);

	Fridge first(10);
	Fridge second(20);
	// не скомпилируется - мы запретили конструктор копирования
	//Fridge third = first;
	// не скомпилируется - мы запретили оператор копирующего присваивания
	//second = first;

	// холодильники не копируются, только перемещатся
	Fridge third = std::move(first);
	second = std::move(first);
}