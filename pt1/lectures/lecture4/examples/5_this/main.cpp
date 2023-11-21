#include "this_class.h"
#include <iostream>
#include <iomanip>


int main()
{
	ThisClass thisTest;
	thisTest.setVal(10);
	const int val = thisTest.getVal();
	std::cout << val << std::endl;
	std::getchar();

	const ThisClass* thisPtr = thisTest.getThis();
	std::cout << "Does \"this\" really point to object's address?\n" <<  
		std::boolalpha << (thisPtr == &thisTest) << std::endl;
}