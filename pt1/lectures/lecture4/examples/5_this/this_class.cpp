#include "this_class.h"
#include <iostream>


int ThisClass::getVal()
{
	return this->_val;
}

void ThisClass::setVal(int val)
{
	this->_val = val;
}

const ThisClass* ThisClass::getThis() const
{
	return this;
}

// не скомпилируется: в статические функции не передаётся указатель this
// void ThisClass::printVal()
// {
// 	std::cout << this->_val << std::endl;
// }

