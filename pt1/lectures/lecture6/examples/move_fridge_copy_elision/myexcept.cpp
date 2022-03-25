#include "myexcept.h"

#include <iostream>

MyException::MyException(const std::string& err) :
	_error(err)
{
	std::cout << "Exception: construction" << std::endl;
};

MyException::MyException(const MyException& other)
{
	std::cout << "Exception: copy construction" << std::endl;
}

MyException::MyException(MyException&& other)
{
	std::cout << "Exception: move construction" << std::endl;
	_error = other._error;
	other._error = "";
}

std::string MyException::reason() const
{
	return _error;
}
