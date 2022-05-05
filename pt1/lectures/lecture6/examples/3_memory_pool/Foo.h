#pragma once

#include <string>
#include <iostream>
#include <stdexcept>


class Foo
{
public:
	Foo(const std::string& name, bool isThrowing = false):
		_name(name)
	{
		std::cout << "Constructing Foo: " << _name << std::endl;

		// Необходимо для демонстрации вызова "правильной" перегрузки operator delete
		// при генерировании исключения в конструкторе 
		if(isThrowing)
		{
			std::cout << "Generating an exception\n"; 
			throw std::exception();
		}
	}

	std::string getName() const
	{
		return _name;
	}

	~Foo()
	{
		std::cout << "Destructing Foo: " << _name << std::endl; 
	}

private:
	std::string _name;
};
