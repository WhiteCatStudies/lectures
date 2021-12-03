#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <functional>

#include "../vector_out.hpp"


void testSearchN()
{
	// Поиск первого появления последовательности из заданного числа повторений
	// заданного элемента
	std::vector<int> vec{ 1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6 };
	std::cout << "Test std::search_n algorithm\n" << vec << std::endl;

	// Поиск трех последовательных элементов, равных 7, во всем векторе
	auto pos = std::search_n(vec.begin(), vec.end(), 3, 7);

	// Если таких элементов нет, возвращается итератор end()
	if (pos != vec.end()) 
	{
		std::cout << "Three consecutive elements with value 7 "
			<< "start with " << std::distance(vec.begin(),pos) + 1 << " element" <<
			std::endl;
	}
	else 
	{
		std::cout << "No three consecutive elements with value 7 found" << 
		std::endl;
	}

	// Поиск четырёх последовательных нечётных элементов
	pos = std::search_n(vec.begin(), vec.end(), 4, 0, 
		[](int elem, int value){return elem % 2 == 1;});

	if (pos != vec.end()) 
	{
		std::cout << "First four consecutive odd elements are: ";
		for (int i = 0; i < 4; ++i, ++pos) 
		{
			std::cout << *pos << "; ";
		}
	}
	else 
	{
		std::cout << "No four consecutive elements with value > 3 found";
	}	
}

void testSearch()
{
	// Поиск появления интервала
	std::deque<int> coll{1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7};
	std::list<int> subcoll{3, 4, 5, 6};

	std::cout << "Test std::serach to find subrange\nCollection: " << coll << 
		"\nSubcollection: " << subcoll << std::endl;

	auto pos = std::search(coll.begin(), coll.end(), 
							subcoll.begin(), subcoll.end());

	while (pos != coll.end()) 
	{
		std::cout << "Subcoll found starting with element " << 
			std::distance(coll.begin(), pos) + 1 << std::endl;
		
		++pos;
		pos = std::search(pos, coll.end(), subcoll.begin(), subcoll.end());
	}

	std::getchar();

	// Поиск появления интервала, соответствующего критерию
	std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << "Find subrange of even, odd, even in\n" << vec << std::endl;
	
	auto checkEven = [](int elem, bool even)
		{return even ? (elem % 2 == 0) : (elem % 2 == 1);};
	bool checkEvenArgs[3] = {true, false, true};

	auto posEven = std::search(vec.begin(), vec.end(),
				checkEvenArgs, checkEvenArgs + 3, checkEven);

	while (posEven != vec.end()) 
	{
		std::cout << "Subrange found starting with element " << 
			std::distance(vec.begin(), posEven) + 1 << std::endl;
		posEven = std::search(++posEven, vec.end(), checkEvenArgs, checkEvenArgs + 3,
					checkEven);
	}
}

void testEqual()
{
	std::vector<int> coll1{1, 2, 3, 4, 5, 6, 7};
	std::list<int> coll2{3, 4, 5, 6, 7, 8, 9};
	std::cout << "Check if collections are equal with std::equal\n" << "coll1 = " <<
		coll1 << "\ncoll2 = " << coll2 << std::endl;

	if (std::equal(coll1.begin(), coll1.end(), coll2.begin()))
	{
		std::cout << "coll1 == coll2" << std::endl;
	}
	else 
	{
		std::cout << "coll1 != coll2" << std::endl;
	}

	std::getchar();
	std::cout << "Check if corresponding elements are both even or both odd" << std::endl;

	if (std::equal(coll1.begin(), coll1.end(), coll2.begin(), 
		[](int elem1, int elem2) {return elem1 % 2 == elem2 % 2;})) 
	{
		std::cout << "Even and odd elements correspond" << std::endl;
	}
	else 
	{
		std::cout << "even and odd elements do not correspond" << std::endl;
	}
}

void testPermutation()
{
	std::vector<int> coll1{1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int> coll2{1, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::deque<int> coll3{11, 12, 13, 19, 18, 17, 16, 15, 14, 11};

	std::cout << "Test if collections are composed of equal elements "\
		"no matter what their order is with std::is_permutation\ncoll1 = " <<
		coll1 << "\ncoll2 = " << coll2 << "coll3 = " << coll3 <<
		"\nCompare coll1 and coll2" <<  std::endl;  

	if (std::is_permutation(coll1.cbegin(), coll1.cend(), coll2.cbegin()))
	{
		std::cout << "coll1 and coll2 have equal elements" << std::endl;
	}
	else 
	{
		std::cout << "coll1 and coll2 don’t have equal elements" << std::endl;
	}

	std::getchar();

	std::cout << "Check if the number of even and odd elements in coll1 and coll3 " \
		"is the same with std::is_permutation" << std::endl;
	
	if(std::is_permutation(coll1.cbegin(), coll1.cend(), coll3.cbegin(), 
			[](int elem1, int elem2) {return elem1 % 2 == elem2 % 2;})) 
	{
		std::cout << "Numbers of even and odd elements match" << std::endl;
	}
	else 
	{
		std::cout << "Numbers of even and odd elements don’t match" << std::endl;
	}
}

void testMismatch()
{
	std::vector<int> coll1{ 1, 2, 3, 4, 5, 6 };
	std::list<int> coll2{ 1, 2, 4, 8, 16, 3 };

	std::cout << "Find the first mismatch with std::mismatch\ncoll1 = " << coll1 << 
		"\ncoll2 = " << coll2 << std::endl;	

	auto values = std::mismatch(coll1.cbegin(), coll1.cend(), coll2.cbegin());
	if (values.first == coll1.end()) 
	{
		std::cout << "no mismatch" << std::endl;
	}
	else 
	{
		std::cout << "First mismatch: " << *values.first << " and "	<< 
			*values.second << std::endl;
	}

	std::getchar();

	std::cout << "Find first position where the element of coll1 is not less than "\
		"the corresponding element of coll2 with std::mismatch" << std::endl;
	
	values = std::mismatch(coll1.cbegin(), coll1.cend(), coll2.cbegin(),
				std::less_equal<int>());

	if (values.first == coll1.end())
	{
		std::cout << "Always less-or-equal" << std::endl;
	}
	else 
	{
		std::cout << "Not less-or-equal: " << *values.first << " and " << 
			*values.second << std::endl;
	}
}

int main()
{
	testSearchN();
	std::getchar();

	testSearch();
	std::getchar();

	testEqual();
	std::getchar();

	testPermutation();
	std::getchar();

	testMismatch();
}