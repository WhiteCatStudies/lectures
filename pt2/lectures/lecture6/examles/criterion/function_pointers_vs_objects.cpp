#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

#include "../vector_out.hpp"
#include "custom_func_obj.hpp"

using cIntVecItT = std::vector<int>::const_iterator; 


bool pred1(int i)
{
	return i < 10;
}

bool pred2(int i)
{
	return (i > 5) && (i < 10); 
}

bool check(const cIntVecItT& first, const cIntVecItT& last, bool(*pred)(int))
{
	// bool(*pred)(int) - указатель на функцию
	// Странный синтаксис. А если это будет более сложная функция? 
	// А если нужно будет передать этот указатель по указателю?
	// В современном C++ есть варианты получше
	return std::all_of(first, last, pred);
}

void testAllOf(const std::vector<int>& vec)
{
	std::cout << "Testing std::all_of\nVector is " << vec << std::endl;
	
	// Внимание! Attention! Achtung! Старый некрасивый синтаксис!
	// Так-то вроде ничего страшного, но может быть гораздо хуже
	std::cout << "Checking with predicate 1. Are all the elements less then 10? " << 
		std::boolalpha << std::all_of(vec.cbegin(), vec.cend(), &pred1);
	std::getchar();


	std::cout << "Checking with predicate 1 again: " << 
		check(vec.cbegin(), vec.cend(), &pred1) << 
		"\nAre all the elements between 5 and 10? " <<
		check(vec.cbegin(), vec.cend(), &pred2);
}
 
void add10 (int& elem)
{
	elem += 10;
}

template<int n>
void add(int& elem)
{
	// Способ не писать новую функцию каждый раз, когда нужно прибавить другое число
	// Но выбрать это число можно только во время компиляции
	// Потом поздно будет!
	// Адекватных способов передать значение в рантайме для указателей на функцию нет
	elem += n;
}

void testForEach(std::vector<int>& vec)
{
	std::cout << "Testing std::for_each\nThe initial vector is " << vec <<
		std::endl;

	// Давайте прибавим ко всем элементам 10
	std::for_each(vec.begin(), vec.end(), add10);
	std::cout << "Added 10. The vector is:\n" << vec << std::endl; 
	std::getchar();

	// А теперь 20. Стоп, это что, надо новую функцию писать?
	std::for_each(vec.begin(), vec.end(), add<20>);
	std::cout << "Added 20. The vector is:\n" << vec << std::endl;
	std::getchar();

	// Прибавим значение, определяемое во время выполнения (в рантайме) 
	int addVal = 0;
	std::cout << "What number to add?" << std::endl;
	std::cin >> addVal;

	std::for_each(vec.begin(), vec.end(), Add<int>(addVal));
	std::cout << "Add value defined at runtime\n" << vec << std::endl;

	// Add - шаблонный класс, его можно использовать для сложения 
	// с любыми значениями любых типов, для которых определена эта операция   
}

void testMean(const std::vector<int>& vec)
{
	std::cout << "Find the average value of:\n" << vec << std::endl;

	const auto mean = std::for_each(vec.cbegin(), vec.cend(), Mean());
	std::cout << "It is " << mean.value() << std::endl; 
}

int main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	testAllOf(vec);
	std::getchar();

	testForEach(vec);
	std::getchar();

	// Функциональные объекты могут иметь состояние (state) - 
	// т.е. сохранять данные 
	testMean(vec);
}