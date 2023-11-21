#pragma once
#include <iostream>


class A
{
public:
	A()
	{
		std::cout << "Construction of A" << std::endl;
	}

	~A()
	{
		std::cout << "Destruction of A" << std::endl;
	}
};


class B : public A
{
public:
	B()
	{
		std::cout << "Construction of B" << std::endl;
	}

	~B()
	{
		std::cout << "Destruction of B" << std::endl;
	}
};


class C : public B
{
public:
	C()
	{
		std::cout << "Construction of C" << std::endl;
	}

	~C()
	{
		std::cout << "Destruction of C" << std::endl;
	}
};
