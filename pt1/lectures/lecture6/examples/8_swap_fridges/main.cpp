#include "fridge.h"

#include <iostream>
#include <utility> // std::move

void swapFridges(Fridge& first, Fridge& second)
{
	// Зачем копировать холодильники, когда их можно перемещать?
	// Без std::move будут вызваны копирующие версии 
	// консруктора и оператора присваивания  
	std::cout << "Moving first fridge to temporary" << std::endl; 

	// несмотря на то, что переменная tmp нигде далее не изменяется,
	// её нельзя объявить константной - перемещающий конструктор \
	// и оператор перемещающего присваивания принимают rvalue-ссылки 
	// на неконстаный объект
	Fridge tmp = std::move(first);
	// Конструктор копирования создал бы лишний временный холодильник
	// Fridge tmp = first;

	std::cout << "Moving second fridge to first" << std::endl;
	first = std::move(second);
	// first = second;

	std::cout << "Moving temporary to second" << std::endl;
	second = std::move(tmp);
	// second = tmp;
}

int main()
{
	// Зачем нужны все эти перемещаюие методы, если они никогда не вызываются?
	// Ответ: std::move!
	Fridge first(10);
	std::cout << "The first fridge is " << first;
	first.put("Fish");
	std::getchar();

	Fridge second(20);
	std::cout << "The second fridge is " << second;
	second.put("Meat");
	std::getchar();

	std::cout << "Lets swap fridges!" << std::endl;
	swapFridges(first, second);
	std::getchar();

	std::cout << "The first fridge is " << first;
	std::cout << first.get() << std::endl;
	std::getchar();

	std::cout << "The second fridge is " << second;
	std::cout << second.get() << std::endl; 
	std::getchar();
	
}