#include <iterator> // advance, next, prev
#include <iostream>
#include <list>

using cForwardItT = std::list<int>::const_iterator;

void testAdvance(cForwardItT pos)
{
	// void advance(InputIterator& pos, Dist n)
	// сдвигает итератор на заданное число элементов
	std::cout << "Testing std::advance" << std::endl; 
	std::cout << "Current position" << std::endl; 
	std::cout << *pos << std::endl;
	std::getchar();
	
	// Сдвиг на 3 вперед
	std::cout << "After std::advance(pos, 3)" << std::endl;
	std::advance(pos, 3);
	std::cout << *pos << std::endl;
	std::getchar();

	// Сдвиг на 1 назад
	std::cout << "After std::advance(pos, -1)" << std::endl;
	std::advance(pos, -1);
	std::cout << *pos << std::endl;
}

void testNext(cForwardItT pos)
{
	// ForwardIterator next(ForwardIterator pos)
	// ForwardIterator next(ForwardIterator pos, Dist n)
	// std::next возвращает значение, на которое указывал бы итератор, 
	// если бы его сдвинули бы на заданное число элементов. 
	// Сам итератор не сдвигается
	std::cout << "Testing std::next" << std::endl;
	std::cout << "Value pointed by pos before calling next\n" <<
		*pos << std::endl;
	std::getchar();

	std::cout << "Value of std::next(pos)\n" << *(std::next(pos)) << std::endl;
	std::getchar();

	std::cout << "Value pointed by pos after calling next\n" <<
		*pos << std::endl;

	// Есть ещё аналогичная функция std::prev
	// BidirectionalIterator prev(BidirectionalIterator pos)
	// BidirectionalIterator prev(BidirectionalIterator pos, Dist n)
}

void testDistance(cForwardItT first, cForwardItT last)
{
	std::cout << "Testing std::distance\nThe distance between " << *first << 
		" and " << *last << " is " << std::distance(last, first) << " elements" <<
		std::endl;
}

int main()
{
	std::list<int> coll;
	for (int i = 1; i <= 9; ++i) 
	{
		coll.push_back(i);
	}

	testAdvance(coll.cbegin());
	std::getchar();

	testNext(coll.cbegin());
	std::getchar();

	testDistance(coll.cbegin(), std::next(coll.cbegin(), 6));
}