#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional> // function, bind

#include "my_function.hpp"
#include "../vector_out.hpp" 
#include "foo.h"

void testOurFunction()
{
	std::cout << "Our own function vs std::function!\n" << std::endl;
	
	int l = 12;
	int i = 10;
	int k = 11;

	auto lambda = [](int x){return x > 10;};
	auto lambda2 = [i, l](int x){return (x > i) && (x < l);};

	MyFunction<bool(int)> myF = lambda;
	MyFunction<bool(int)> myF2 = lambda2;
	std::function<bool(int)> f = lambda;
	std::function<bool(int)> f2 = lambda2; 


	std::cout << "Is " << l << " greater than 10?\n" << std::boolalpha << 
		"MyFunction: " << myF(l) << "\nstd::function: " << f(l) <<  
		"\nIs " << k << " greater then " << i << " and less then " << l 
		<< "?\nMyFunction: " << myF2(k) << "\nstd::function: " << f2(k) << 
		std::endl;
}

void printNum(int i)
{
    std::cout << i << std::endl;
}
 

void testStdFuntion()
{
	std::function<void(int)> fDisplay = &printNum;
	std::function<void(int)> objDisplay = PrintNum();
	std::function<void(int)> bindDispaly = std::bind(printNum, 38);
	std::function<int(const Foo&)> memberGetter = &Foo::num;
	std::function<void(const Foo&, int)> memberFunction = &Foo::printAdd; 

    auto foo = Foo(19);
	
	std::cout << "Test std::function\nYou can store function pointer\n";
    fDisplay(-9);
    std::cout << "and function object\n";
    objDisplay(42);
    std::cout << "and binder\n";
    bindDispaly(84);

    std::cout << "and memeber data getter\n" << memberGetter(foo) <<
    	"\nand member function\n";

    memberFunction(foo, 1);
}

void lambdaSort(std::vector<int>& vec, const std::function<bool(int, int)>& func)
{
	std::cout << "Usorted: " << vec << std::endl;
	std::sort(vec.begin(), vec.end(), func);
	std::cout << "Sorted: " << vec << std::endl; 
}

void testFunctionPass()
{
	std::cout << "Pass lambda as std::function and sort decreasing\n";

	std::vector<int> vec = {4, 7, 3, 1, 9, 55, 31, 90, 8};
	lambdaSort(vec, [](int a, int b) {return a > b;});
}

int main()
{
	// Проверим, что наша собственная реализация type erasure 
	// ведёт себя так же как и std::function
	testOurFunction();
	std::getchar();

	// std::function позволяет хранить объекты любых типов,
	// которые определяют их вызов как функцию 
	testStdFuntion();
	std::getchar();

	// Передача лямбды в функцию через std::function
	testFunctionPass();
}