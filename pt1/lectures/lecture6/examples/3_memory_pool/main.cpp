/*
Использование placement-new в реализации пула памяти
Источник: https://isocpp.org/wiki/faq/dtors#memory-pools
*/

#include "Pool.h"
#include "Foo.h"


void printFooInfo(const Foo* fooPtr)
{
	std::cout << "Name: " << fooPtr->getName() << 
		"; address: " << fooPtr << std::endl; 
}

void printDifference(const Foo* first, const Foo* second)
{
	std::cout << "Difference: " << (second - first) << std::endl;
}


int main()
{
	const size_t poolSize = 10;
	Pool pool(poolSize);
	
	std::cout << "Constructing some Foos\n";
	// Без перегрузки оператора new было бы 
	// new(pool.alloc(sizeof(Foo))) Foo()
	Foo* first = new(pool) Foo("First");
	std::getchar();

	Foo* second = new(pool) Foo("Second");
	std::getchar();

	Foo* third = new(pool) Foo("Third");
	std::getchar();

	std::cout << "Some info on Foos\nsizeof(Foo) is " << sizeof(Foo) << "\n";
	printFooInfo(first);
	printFooInfo(second);
	printDifference(first, second);
	printFooInfo(third);
	printDifference(second, third);
	std::getchar();

	std::cout << "Deleting Foos\n";
	delete first;
	std::cout << "First is deleted\n"; 
	std::getchar();

	delete second;
	std::cout << "Second is deleted\n";
	std::getchar();

	delete third;
	std::cout << "Third is deleted\n";
	std::getchar();

	try
	{
		std::cout << "Checking exception handling\n";
		Foo* throwing = new(pool) Foo("Throwing", true);
	}
	catch(...)
	{
		std::cerr << "Error constructing Foo\n";
		return 1;
	}

	return 0;
}