#pragma once
#include <iostream>


class MyClass
{
public:
	MyClass()
	{
		std::cout << "MyClass::MyClass()" << std::endl;
	}

	~MyClass()
	{
		std::cout << "MyClass::~MyClass()" << std::endl; 
	}

	bool checkThis(const MyClass* ptr) const
	{
		return ptr == this;
	}
};
