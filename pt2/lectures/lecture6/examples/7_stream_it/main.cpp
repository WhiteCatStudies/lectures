#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


void testOstream()
{
	std::cout << "Test ostream iterators" << std::endl;

	std::ostream_iterator<int> intWriter(std::cout, "\n");
	*intWriter = 42;
	intWriter++;
	*intWriter = 77;
	intWriter++;
	*intWriter = -5;
	std::getchar();

	std::vector<int> coll = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// Скопировать все элементы в stdout без разделителя
	std::copy(coll.cbegin(), coll.cend(),
		std::ostream_iterator<int>(std::cout));
	std::getchar();

	// Скопировать все элементы в stdout с разделителем " < "
	std::copy(coll.cbegin(), coll.cend(),
		std::ostream_iterator<int>(std::cout," < "));
}

void testIstream()
{
	std::cout << "Test istream iterators" << std::endl;

	std::istream_iterator<int> intReader(std::cin);
	// Конструктор по умолчанию создаёт end-of-file итератор - 
	// аналог итератора, возвращаемого end() у контейнеров
	// Если ввод по какой-либо причине невозможен, итератор примет это значение
	std::istream_iterator<int> intReaderEOF;

	while (intReader != intReaderEOF) 
	{
		std::cout << "once: " << *intReader << std::endl;
		std::cout << "once again: " << *intReader << std::endl;
		++intReader;
	}

	std::cout << "The end!" << std::endl;
}

int main()
{
	testOstream();
	std::getchar();

	testIstream();
}