#include "diamond.h"
#include <iostream>

A::A(int i): 
	_i(i)
{
	std::cout << "Consctuction of A" << std::endl;
}

A::~A()
{
	std::cout << "Destruction of A" << std::endl;
}

B::B(int i, int j): 
	A(i), _j(j)
{
	std::cout << "Construction of B" << std::endl;
}

B::~B()
{
	std::cout << "Destruction of B" << std::endl;
}

C::C(int i, int k) :
	A(i), _k(k)
{
	std::cout << "Construction of C" << std::endl;
}

C::~C()
{
	std::cout << "Destruction of C" << std::endl;
}

D::D(int i, int j, int k) : 
	B(i, j), C(i, k), A(i)
{
	std::cout << "Construction of D" << std::endl;
}

int D::getSum()
{
	return _i + _j + _k;
}

D::~D()
{
	std::cout << "Destruction of D" << std::endl;
}