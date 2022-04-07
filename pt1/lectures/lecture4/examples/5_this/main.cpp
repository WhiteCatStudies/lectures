#include "this_class.h"
#include <iostream>

int main()
{
	ThisClass thisTest;
	thisTest.setVal(10);
	const int val = thisTest.getVal();
	std::cout << val << std::endl;
}