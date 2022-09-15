#include <string>
#include <array>
#include <vector>
#include <initializer_list>

#include <iostream>
#include <iomanip>

#include <stdexcept>

template<class T, size_t N>
void printArray(const std::array<T, N>& arr)
{
	for (const T& elem: arr)
	{
		std::cout << elem << " ";
	}

	std::cout << std::endl;
}

int main()
{
	// Конструктор по умолчанию не инициализирует элементы массива
	// Скорее всего в массиве будет мусор
	std::array<int, 4> garbageArr;
	std::cout << "Unintialized array" << std::endl;
	printArray(garbageArr);
	std:getchar();

	// Инициализация пустым "{}"
	// вызывает конструкторы элементов по умолчанию
	std::array<int, 4> zeroArr = {};
	std::cout << "Empty initializer list" << std::endl;
	printArray(zeroArr);
	std::getchar();

	// Массив - это составной тип (aggregate), следовательно, к нему применимы правила
	// aggregate initialization
	// static const int arrSize = 4;
	// constexpr - гарантирует, что значение известно во время компиляции 
	constexpr int arrSize = 3;
	std::array<int, arrSize> initArr = {1, 2, 3};

	// Составные типы не должны иметь нестатических приватных или защищённых членов данных
	// В данной реализации STL статический массив, для которого предоставляет интерфейс std::array,
	// является открытым нестатическим членом данных класса:
	// Интерфейс для прямого доступа к нему не определён. 
	// Нет гарантии, что это в другой реализации STL он называется так же 
	int* ptr = initArr._M_elems;
	std::cout << "Getting members by raw pointer:\n" << *ptr << " " << *(ptr + 1) << std::endl;
	std::getchar();

	// Механизм инициализации std::array можно принять за инициализацию списком,
	// но это не она. В противном случае std::array имел бы конструктор
	// и оператор копирующего присваивания, принимающий как параметр std::initializar_list

	const std::initializer_list<std::string> init = {"Anna", "loves", "kittens"};
	// To же, что и
	// std::vector<std::string> strVec({"Anna", "loves", "kittens"});
	std::vector<std::string> strVec(init);

	// Попробуем так же с std::array:
	// Ошибка! Такого конструктора у std::array нет
	// std::array<std::string, 3> strArr(init);

	std::array<std::string, arrSize> testArray = {"Anna", "loves", "kittens"};
	// Доступ к произвольному элементу при помощи оператора индексирования: O(1)
	std::cout << "Testing member access" << std::endl;
	std::cout << "Indexing operator: The second element is: " << testArray[1] << std::endl;
	// Оператор индексирования не проверяет границы массива:

	std::cout << "Indexing operator: The tenth element is: " << testArray[10] << std::endl;
	std::getchar();
	// А метод at() кидает std::out_of_range при нарушении границ

	try
	{
		std::cout << "at(size_t) method: The tenth element is: " << std::endl;
		std::cout << testArray.at(10) << std::endl;
	}
	catch(const std::out_of_range& err)
	{
		std::cout << err.what() << std::endl;
	}

	//Доступ к первому элементу: О(1)
	std::cout << "front() mehod: The first element is: " << testArray.front() << std::endl;
	std::getchar();

	// Доступ к поледнему элементу: O(1)
	std::cout << "back() method: The last element is: " << testArray.back() << std::endl;
	std::getchar();

	// Доступ к массиву (underlying array): O(1) 
	std::cout << "Underlying array pointer: " << testArray.data() <<
		 "\nFirst element address: " << &(testArray[0]) << std::endl;
	std::getchar();

	// Проверка, пустой ли массив: О(1)
	std::cout << "Does Anna love anybody? " << std::boolalpha << 
		!(testArray.empty()) << std::endl;
	std::getchar();

	// Получение размера и максимального значения размера массива: О(1)
	// Поскольку массив статический, они всегда равны:
	std::cout << "Array size: " << testArray.size() << "\nMaximum array size: " <<
		testArray.max_size() << std::endl;
	std::getchar();

	// Интератор на начало массива
	// тип итератора - std::array<int>::iterator
	auto it = testArray.begin();
	// итератор std::array поддерживает произвольный доступ, т.е. это 
	// RandomAccessIterator 
	it += 2;
	*it = "Puppies";
	printArray(testArray);
	std::getchar();

	// Итератор на ячейку памяти, следующую за концом массива
	auto endIt = testArray.end();
	std::string* endPtr = testArray.data() + testArray.size();
	std::cout << "Does end iterator really point after end? " << 
		(endIt == endPtr) << std::endl;

	std::getchar();

	std::cout << "Use iterators in a loop" << std::endl;
	for (auto it = testArray.begin(); it != testArray.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::getchar();

	// Аналогично можно получить константные итераторы:
	auto cit = testArray.cbegin();
	// Сам итератор неконстантный
	++cit;
	// А вот то, на что он указывает, уже константное
	// Нельзя так с щеночками
	// *cit = "hates";

	// У пустого массива итератор на начало равен итератору на конец
	std::cout << "Check iterators on empty array" << std::endl;
	std::array<int, 0> emptyArray;
	std::cout << "Is array empty? " << (emptyArray.begin() == emptyArray.end()) 
		<< std::endl;
	std::getchar();

	auto rBegin = testArray.rbegin();
	std::cout << "Reverse begin iterator points to " << (*rBegin) << std::endl;

	auto rEnd = testArray.rend();
	// (&(*rEnd)) - мда
	std::cout << "Does reverse end iterator point before the beginning? " << 
		(&(*rEnd) == (testArray.data() - 1)) << std::endl;

	std::cout << "Print array in reverse order" << std::endl;

	for (auto it = testArray.rbegin(); it != testArray.rend(); ++it)
	{
		std::cout << *it << " ";
	}

	std::getchar();

	std::array<std::string, arrSize> newArray;
	newArray.fill("Blah");

	auto newIt = newArray.begin();
	std::cout << "First element of new array: " << *newIt << std::endl;

	newArray.swap(testArray);
	std::cout << "New array after swap" << std::endl;
	printArray(newArray);
	std::cout << "New array begin iterator after swap: " << *newIt << std::endl;
}
