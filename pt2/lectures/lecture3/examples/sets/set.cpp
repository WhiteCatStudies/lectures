#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

void testBounds()
{
	std::set<int> c;
	c.insert(1);
	c.insert(2);
	c.insert(4);
	c.insert(5);
	c.insert(6);
	
	// итератор на первый элемент, больший либо равный данному
	// т.е. позицию, куда был бы вставлен данный элемент
	std::cout << "lower_bound(3): " << *c.lower_bound(3) << std::endl;

	// итератор на первый элемент, строго больший данного
	// т.е. позицию, куда был бы вставлен данный элемент
	std::cout << "upper_bound(3): " << *c.upper_bound(3) << std::endl;

	// std::pair<iterator, iterator>
	// first указывает на элемент, больший либо равный данному
	// second - на элемент, строго больший данного
	// т.е. позицию, куда... был бы вставлен данный элемент
	std::cout << "equal_range(3): " << *c.equal_range(3).first << " "
		<< *c.equal_range(3).second << std::endl;
	
	std::getchar();

	std::cout << "lower_bound(5): " << *c.lower_bound(5) << std::endl;
	std::cout << "upper_bound(5): " << *c.upper_bound(5) << std::endl;
	std::cout << "equal_range(5): " << *c.equal_range(5).first << " "
		<< *c.equal_range(5).second << std::endl;

}


int main()
{
	testBounds();	
	std::getchar();

	// type of the collection:
	// - no duplicates
	// - elements are integral values
	// - descending order
	std::set<int, std::greater<int>> coll1;
	coll1.insert({4, 3, 5, 1, 6, 2});
	coll1.insert(5);
	for (int elem : coll1) 
	{
		std::cout << elem << " ";
	}

	std::cout << std::endl;
	
	// insert возвращает std::pair<iterator,bool>
	// итератор на вставленный элемент или на элемент, препятствоваший вставке
	// второе значение - успех или неуспех вставки (если такой элемент уже есть)
	auto status = coll1.insert(4);
	if (status.second) 
	{
		std::cout << "4 inserted as element "
			<< distance(coll1.begin(), status.first) + 1 << std::endl;
	}
	else 
	{
		std::cout << "4 already exists" << std::endl;
	}
	
	std::set<int> coll2(coll1.cbegin(), coll1.cend());
	// print all elements of the copy using stream iterators
	std::copy(coll2.cbegin(), coll2.cend(), std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;
	// remove all elements up to element with value 3
	coll2.erase(coll2.begin(), coll2.find(3));
	// remove all elements with value 5
	int num = coll2.erase (5);
	std::cout << num << " element(s) removed" << std::endl;
	// print all elements
	std::copy(coll2.cbegin(), coll2.cend(), std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;
}