#include "exception_base.h"
#include <iostream>


StudentExceptionBase::StudentExceptionBase(const std::string& reason) :
	_reason(reason)
{
}

StudentExceptionBase::StudentExceptionBase(const StudentExceptionBase& other)
{
	std::cout << "Copy construction of exception" << std::endl;
	_reason = other._reason;
}

std::string StudentExceptionBase::getReason() const
{
	return _reason;
}


LateException::LateException() :
	StudentExceptionBase("It is too late")
{
}

BadLuckException::BadLuckException() :
	StudentExceptionBase("It is a bad luck")
{
}