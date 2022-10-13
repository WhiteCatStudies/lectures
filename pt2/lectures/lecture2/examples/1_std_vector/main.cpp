#include <vector>
#include <limits>
#include <iostream>
#include <iomanip>

#include <math.h>

#include <stdexcept> 


#include "my_alloc.h"

void testCapacity()
{
	std::vector<int> testVec;

	// Максимальное число элементов, которое теоретически можно хранить в векторе
	// На парктике будет меньше из-за ограничений по RAM
	const size_t maxTypeVal = std::numeric_limits<size_t>::max(); 
	std::cout << "Maximum theoretical number of integer elements in vector is " << 
		testVec.max_size() << std::endl;  

	size_t prevCapacity = 1;
	const size_t max = testVec.max_size();

	while(testVec.size() < max)
	{
		testVec.push_back(42);
		size_t curSize = testVec.size();
		size_t curCapacity = testVec.capacity();

		if(curCapacity > prevCapacity)
		{
			std::cout << "Size is " << curSize << " Capacity is " << curCapacity <<
				" Capacity increased by " << 
				static_cast<double>(curCapacity) / prevCapacity  << std::endl; 
			
		}

		prevCapacity = curCapacity;
	}
}

template <class T>
void printFirst(const std::vector<T>& v, size_t num=5)
{
	const size_t print = v.size() < num ? v.size() : num;

	for(int i = 0; i < print; ++i)
	{
		std::cout << v[i] << " ";
	}

	std::cout << std::endl;
}

template<class T>
void printSizeCapacity(const std::vector<T>& vec)
{
	std::cout << "Size: " << vec.size() << "; Capacity: " << vec.capacity() << 
		std::endl;
}

void swapTrick()
{
	std::vector<int> first;
	first.resize(100);
	first.resize(50);
	
	std::cout << "First vector before" << std::endl;
	printSizeCapacity(first);

	std::vector<int> second;
	second.resize(50);
	std::cout << "Second vector" << std::endl;
	printSizeCapacity(second);

	std::swap(first, second);
	std::cout << "First vector after swap" << std::endl;
	printSizeCapacity(first);
}

void testResize()
{
	// Выделенная память не освобождается ни при вызове clear(), ни после resize() 
	// до меньшего размера, ни после pop_back()
	// Начиная с С++ 11 есть метод shrink_to_fit(), освобождающий незанятую память
	std::cout << "-----Testing resize() and shrink_to_fit()-----" 
		<< std::endl;

 	std::vector<int> v;
    std::cout << "Default-constructed" << std::endl;
    printSizeCapacity(v);
    std::getchar();

    v.resize(100);
    std::cout << "resize(100)" << std::endl;
    printSizeCapacity(v);
    std::getchar();

    v.resize(50);
    std::cout << "resize(50)" << std::endl;
    printSizeCapacity(v);
    std::getchar();

    // shrink_to_fit позволяет уменьшить capacity до size 
    v.shrink_to_fit();
    std::cout << "shrink_to_fit()" << std::endl;
    printSizeCapacity(v);
    std::getchar();

    v.clear();
    std::cout << "clear()" << std::endl;
    printSizeCapacity(v);
    std::getchar();

    // shrink_to_fit появился только в C++ 11
    // раньше с этой целью приходилось использовать swap trick
    std::cout << "Testing old good swap trick" << std::endl;
    swapTrick();
    std::getchar();

    // Resize изменяет размер вектора (size), значит, создаёт элементы 
    // (инстанциирует)
    // По умолчанию resize вызывает конструктор по умолчанию для элемента вектора 
	v.resize(2);
	v.push_back(42);
	std::cout << "Default resize" << std::endl;
	printFirst(v);
	std::getchar();

	v.clear();
	v.resize(3, 11);
	v.push_back(42);
	std::cout << "Resize with element value" << std::endl;
	printFirst(v);
}

void testReserve()
{
	// reserve() выделяет память, но не инициализирует элементы
	// и не увеличивает размер 
    std::cout << "-------Testing reserve()-------" << std::endl;
    
    std::vector<int> reserveTest;
    std::cout << "Default constructed" << std::endl;
    printSizeCapacity(reserveTest);
    std::getchar();

    reserveTest.reserve(50);
    std::cout << "reserve(50)" << std::endl;
    printSizeCapacity(reserveTest);
    std::getchar();

    reserveTest.reserve(2);
    reserveTest.push_back(42);
    std::cout << "Elements after reserving 2 and pushing back" << '\n';
    printFirst(reserveTest);
    printSizeCapacity(reserveTest);
    std::getchar();
}

void testInsert()
{
	// Вставка элемента на произвольную позицию: 
	std::cout << "-------Test insert--------" << std::endl;

    std::cout << "Testing arbitrary position insertions\n";
    std::vector<int> vec(3, 100);
    auto it = vec.begin();
    
    std::cout << "Before insertions\n";
    printFirst(vec);
    printSizeCapacity(vec);
    std::cout << "Begin iterator points to address " << &(*it) << '\n' << 
    	"Array starts at " << &vec[0] << std::endl;
 	std::getchar();

    vec.insert(it, 200); 
    std::cout << "Insert 200 in the beginning\n";
    printFirst(vec);
   	printSizeCapacity(vec);
   	// После предыдущей операции была выделена другая память, 
   	// но итреатор указывает на старый адрес, т.е. итератор инвалидирован
   	// Результат - segfault или некорректное поведение 
   	// при использовании такого итератора
    std::cout << "Begin iterator points to address " << &(*it) << '\n' << 
    	"Array starts at " << &vec[0] << std::endl;
    std::getchar();

    // Аналогичное поведение для всех операций, реаллоцирующих память 
    // т.е. push_back тоже

    // Попытка использовать инвалидированный итератор для указания
    // поизиции вставки
    /* 
    std::cout << "Insert 300; 300 in the beginning\n" <<
    	"Insert position is pointed by invalidated iterator" << std::endl;
    vec.insert(it, 2, 300);
    printFirst(vec);
    */

    // Поскольку мы не знаем точно, как увеличивается capacity 
    // в данной реализации STL, лучше брать новый итератор 
    // после каждой операции, потенциально изменяющей capacity
    std::cout << "Insert position is pointed by correct iterator\n" <<
    	"Insert in the beginning" << std::endl;
    vec.insert(vec.begin(), 2, 300);
    printFirst(vec);

    std::cout << "Insert on the third position" << std::endl;
    vec.insert(vec.begin() + 2, 500);
    printFirst(vec);
}

void testErase()
{
	std::cout << "------Testing erase-------" << std::endl;
	std::vector<int> numbers{1, 2, 3, 4, 5};
	std::cout << "Intial state"<< std::endl;
	printFirst(numbers);
	std::getchar();

	const auto beg = numbers.begin();
	auto thirdIt = beg + 2;
	auto lastIt = numbers.end() - 1;
	std::cout << "Third element is " << *thirdIt << 
		"\nErasing the third element" << std::endl;
	numbers.erase(thirdIt);
	printFirst(numbers);

	// erase инвалидирует итераторы на все элементы,
	// следующие за позицией удаления (включая последнюю)
	// после erase тоже лучше взять новый итератор - это недорогая операция
	std::cout << "Dereference the third element iterator: " << (*thirdIt) << std::endl;
	std::cout << "Dereference the last element iterator: " << (*lastIt) << std::endl;
}

int main()
{
	std::cout << "Test this useless custom allocator" << std::endl;
	// Конструктор со списком инициализации
	std::vector<int, MyAlloc<int>> cutomAllocVector {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::getchar();

	try
	{
		//testCapacity();
	}
	catch(const std::bad_alloc& e)
	{
		std::cout << "bad_alloc: " << e.what() << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << "other error: " << e.what() << std::endl;
	}

	testResize();
    std::getchar();
    
    testReserve();
    std::getchar();

	testInsert();    
 	std::getchar();

 	testErase();
}