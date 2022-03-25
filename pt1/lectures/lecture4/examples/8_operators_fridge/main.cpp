#include "fridge.h"

int main()
{
	std::cout << "Create two different empty fridges and assign one another" << std::endl;
	Fridge first(10);
	Fridge second(15);
	// для Fridge определён оператор копирующего присваивания 
	first = second;
	getchar();

	std::cout << "Lets put some food" << std::endl;
	first.put("Pelmeni");
	first.put("Old kolbasa");
	first.put("Borshcht");
	getchar();

	std::cout << "Lets get the first item" << std::endl;
	std::string item = first[0];
	std::cout << "The first item is " << item << std::endl;
	getchar();

	// оператор индексирования возвращает ссылку на объект из массива
	// поэтому с его помощью можно менять значения в массиве
	std::cout << "Lets reassign the first item" << std::endl;
	first[0] = "Half of pelmeni";
	item = first[0];
	std::cout << "The first item is " << item << " now" << std::endl;

	std::cout << "Enter the food you want to put to the fridge" << std::endl;
	std::cin >> first;

	const std::string descr = first();
	std::cout << descr << std::endl;
	getchar();
}