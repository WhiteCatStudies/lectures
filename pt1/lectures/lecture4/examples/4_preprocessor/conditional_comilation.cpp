#include <iostream>

#define LAZY

int main()
{
// Флаг условной компиляции LAZY определяет, какая часть кода 
// останется в исходном коде после препроцессинга 
// и будет в дальнейшем скомпилирована

#ifdef LAZY
	std::cout << "I gonna sleep on saturday" << std::endl;
#else
	std::cout << "I go study on saturday" << std::endl;
#endif
}