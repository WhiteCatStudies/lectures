#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "../vector_out.hpp"

using cIntVecItT = std::vector<int>::const_iterator;


void testMinMax(const cIntVecItT& begin, const cIntVecItT& end, 
	const cIntVecItT& first, const cIntVecItT& last)
{
	assert(first >= begin);
	assert(last > first);

	const auto firstNum = first - begin + 1;
	const auto lastNum = (last == end) ? (last - begin) : (last - begin + 1);

	const auto minIt = std::min_element(first, last);
	std::cout << "The minimum element in range from element number " << firstNum <<
		" to element number " << lastNum << " is " << *minIt << std::endl;

	const auto maxIt = std::max_element(first, last);
	std::cout << "The maximum element in range from element number " << firstNum << 
		" to element number " << lastNum << " is " << *maxIt << std::endl;
}

int main()
{
	std::vector<int> coll = { 2, 5, 4, 1, 6, 3 };
	std::cout << "Initial vector is " << coll << std::endl;

	const auto cbeg = coll.cbegin();
	const auto cend = coll.cend();
	testMinMax(cbeg, cend, cbeg, coll.cend());
	std::getchar();

	testMinMax(cbeg, cend, cbeg, cbeg + 3);
	std::getchar();

	testMinMax(cbeg, cend, cbeg + 1, cbeg + 4);
	std::getchar();
}