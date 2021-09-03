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

void testResize()
{
	// Выделенная память не освобождается при вызове clear() и после resize() 
	// до меньшего размера
	// Нужно вызывать shrink_to_fit()
	std::cout << "Testing resize() and shrink_to_fit()" << "\n";

 	std::vector<int> v;
    std::cout << "Default-constructed capacity is " << v.capacity() << '\n';
    v.resize(100);
    std::cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';

    v.resize(50);
    std::cout << "Capacity after resize(50) is " << v.capacity() << '\n' <<
    	"Size after resize is " << v.size();
    v.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
    v.clear();
    std::cout << "Capacity after clear() is " << v.capacity() << 
		"\nSize after clear is " << v.size() << "\n";

    std::cout << "Elements after calling resize(2) and then pushing back" << "\n";
	v.resize(2);
	v.push_back(42);
	printFirst(v);
	
    v.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
    for (int i = 1000; i < 1300; ++i)
        v.push_back(i);
    std::cout << "Capacity after adding 300 elements is " << v.capacity() << '\n';
    v.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << std::endl;
}

void testReserve()
{
	// reserve() выделяет память, но не инициализирует элементы и не увеличивает размер 
    std::cout << "Testing reserve()" << "\n";
    
    std::vector<int> reserveTest;
    std::cout << "Size before reserve is " << reserveTest.size() << 
    	"\nCapacity before reserve is " << reserveTest.capacity() << '\n';

    reserveTest.reserve(2);
    reserveTest.push_back(42);
    std::cout << "Elements after reserving 2 and pushing back" << '\n';
    printFirst(reserveTest);
    reserveTest.clear();

    reserveTest.reserve(50);
    std::cout << "Size after reserve(50) is " << reserveTest.size() << 
    	"\nCapacity after reserve(50) is " << reserveTest.capacity() << std::endl;

    printFirst(reserveTest);

}

void testInsert()
{
	// Вставка элемента на произвольную позицию: 
    std::cout << "Testing arbitrary position insertions\n";
    std::vector<int> vec(3,100);
    auto it = vec.begin();
    std::cout << "Before insertions\n";
    printFirst(vec);
    std::cout << "Capacity is " << vec.capacity() << '\n' << 
    	"Iterator points to address " << &(*it) << '\n';
 	std::getchar();


    // Как исправить проблему, которая возникнет в (3):
    // возвращает итератор на позицию вставки
    //it = vec.insert(it, 200); //(1)
    vec.insert(it, 200); // (2)
    std::cout << "Insert 200 in the beginning\n";
    printFirst(vec);
    std::cout << "Capacity is " << vec.capacity() << '\n' <<
    	"Iterator points to address " << &(*it) << '\n';
    std::getchar();

    // (3) После предыдущей операции была выделена другая память, но итреатор указывает на старый адрес. 
    // Скорее всего, будет segfault, еси раскомментирована строчка (2). 
    // Если раскомментирована (1), it будет указывать на позицию вставки, т.е. на начало
    // Тогда всё будет ОК. Но лучше последующих операциях снова просить begin()
    std::cout << "Insert 300; 300 in the beginning\n";
    it = vec.insert(it, 2, 300);
    printFirst(vec);
    std::cout << "Capacity is " << vec.capacity() << '\n' <<
    	"Iterator points to address " << &(*it) << '\n';
}

int main()
{
	std::cout << "Useless custom allocator" << std::endl;
	// Конструктор со списком инициализации
	std::vector<int, MyAlloc<int>> cutomAllocVector {1,2,3,4,5,6,7,8,9};

	std::vector<int> testVec;

	// Максимальное число элементов, которое теоретически можно хранить в векторе
	// На парктике будет меньше из-за ограничений по RAM
	const size_t maxTypeVal = std::numeric_limits<size_t>::max(); 
	std::cout << "Maximum theoretical number of integer elements in vector is " << 
		testVec.max_size() << std::endl;  

	std::getchar();

	// На практике на моей системе процесс убивается сигкиллом 
	// задолго до достижения максимального значения и никакого исключения не выбрасывается 

	try
	{
		//testCapacity();
	}
	catch(const std::length_error& e)
	{
		std::cout << "length_error: " << e.what() << std::endl;
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
}