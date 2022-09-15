#include "exception.h"
#include <iostream>


StudentException::StudentException(const std::string& reason) :
	_reason(reason)
{
}

StudentException::StudentException(const StudentException& other)
{
	std::cout << "Copy construction of exception" << std::endl;
	_reason = other._reason;
}

std::string StudentException::getReason() const
{
	return _reason;
}