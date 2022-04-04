#include <iostream>

template <int N>
struct Factorial 
{
	static const unsigned long value = N * Factorial<N - 1>::value;
};


template <>
struct Factorial<0> 
{
	// рекурсивные вызовы прекращаются при N = 0 
	static const unsigned long value = 1;
};

int main()
{
	std::cout << Factorial<3>::value << std::endl;		
	std::cout << Factorial<4>::value << std::endl;		
	std::cout << Factorial<5>::value << std::endl;		
}
