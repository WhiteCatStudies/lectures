#pragma once
#include <string>

class MyException
{
public:
	MyException(const std::string& err);
	MyException(const MyException& other);
	MyException(MyException&& other);

	std::string reason() const;

private:
	std::string _error;
};