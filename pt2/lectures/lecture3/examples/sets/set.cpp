#include <iostream>
#include <set>
#include <iterator>


template <class SetT>
void testBounds(const SetT& coll, const typename SetT::value_type& val)
{
	// итератор на первый элемент, больший либо равный данному
	// т.е. позицию, куда был бы вставлен данный элемент
	std::cout << "lower_bound(" << val << "): " << *coll.lower_bound(val) << std::endl;

	// итератор на первый элемент, строго больший данного
	// т.е. позицию, куда был бы вставлен данный элемент
	std::cout << "upper_bound(" << val << "): " << *coll.upper_bound(val) << std::endl;

	// std::pair<iterator, iterator>
	// first указывает на элемент, больший либо равный данному
	// second - на элемент, строго больший данного
	// т.е. позицию, куда... был бы вставлен данный элемент
	std::cout << "equal_range(" << val << "): " << *coll.equal_range(val).first << " "
		<< *coll.equal_range(val).second << std::endl;
}

template <class SetT>
void traverse(const SetT& coll)
{
	// range based loop использует итераторы
	// аналогично for(SetT::iterator it = set.begin(); it != set.end(); ++it)
	for (const auto elem : coll) 
	{
		std::cout << elem << " ";
	}
}

template <class SetT>
void testInsert(SetT& coll, const typename SetT::value_type& val)
{
	// insert возвращает std::pair<iterator,bool>
	// итератор на вставленный элемент или на элемент, препятствоваший вставке
	// второе значение - успех или неуспех вставки (если такой элемент уже есть)
	const auto status = coll.insert(val);
	if (status.second) 
	{
		std::cout << val << " inserted as element "
			<< std::distance(coll.begin(), status.first) + 1 << std::endl;
	}
	else 
	{
		std::cout << val << " already exists" << std::endl;
	}
}

template <class SetT>
void inRange(const SetT& coll, const typename SetT::value_type& start, 
	const typename SetT::value_type& end)
{
	const auto startIt = coll.upper_bound(start);
	auto endIt = coll.upper_bound(end);
	std::copy(startIt, --endIt, std::ostream_iterator<typename SetT::value_type>(std::cout, " "));
}


int main()
{
	std::set<int> coll;
	coll.insert({4, 3, 5, 1, 6, 2});
	std::cout << "Depth-first in-order set traverdal: ascending\n"; 
	traverse(coll);
	std::getchar();

	std::set<int, std::greater<int>> collGreater{4, 3, 5, 1, 6, 2, 5};
	std::cout << "Depth-first in-order set traverdal: descending\n"; 
	traverse(collGreater);
	std::getchar();

	std::cout << "Try insert duplicate\n";
	testInsert(coll, 4);
	std::getchar();

	std::cout << "Insert new element\n";
	testInsert(coll, 10);
	std::getchar();
	
	std::cout << "Test bounds\n";
	testBounds(coll, 4);
	std::getchar();
	testBounds(coll, 8);
	std::getchar();

	const int start = 2;
	const int end = 6;
	std::cout << "Get elements in range (" << start << "; " << end << ")\n";
	inRange(coll, start, end);
	std::getchar();

	std::cout << "Insert duplicates to multiset\n"; 
	std::multiset<int> multicoll(coll.begin(), coll.end());
	multicoll.insert(4);
	multicoll.insert(4);
	multicoll.insert(4);
	multicoll.insert(4);
	std::copy(multicoll.begin(), multicoll.end(), std::ostream_iterator<int>(std::cout, " "));
}