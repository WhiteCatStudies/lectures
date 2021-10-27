#include <iostream>
#include <string>

#include "tuple.h"

int main()
{
	tuple<int, double, int, std::string> t(12, 2.34, 89, std::string("Anna"));
	// Нужен рекусивный геттер
	std::cout << t.head << " " << t.base.head << " " << t.base.base.head <<
		std::endl;

	std::cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << 
		" " << get<3>(t) << std::endl;
}