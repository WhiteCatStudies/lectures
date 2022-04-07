#include <string>
#include <iostream>
#include <utility>

#include "cat.h"

void swap(int& a, int& b)
{
	std::cout << "Swap integers" << std::endl; 
	std::cout << "A is " << a << "\nB is " << b << std::endl;

	int tmp = a;
	a = b;
	b = tmp;

	std::cout << "Swap!" <<
		"\nA is " << a << "\nB is " << b << std::endl;
}

void swap(std::string& a, std::string& b)
{
	std::cout << "Swap strings" << std::endl;
	std::cout << "A is " << a << "\nB is " << b << std::endl;

	std::string tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);

	std::cout << "Swap!" <<
		"\nA is " << a << "\nB is " << b << std::endl;
}

void swap(Cat& a, Cat& b)
{
	std::cout << "Swap cats" << std::endl; 
	std::cout << "A is " << a << "\nB is " << b << std::endl;

	Cat tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);

	std::cout << "Swap!" <<
		"\nA is " << a << "\nB is " << b << std::endl;
}

template<class T>
void goodSwap(T& a, T& b)
{
	std::cout << "Good swap with templates!" << std::endl;
	std::cout << "A is " << a << "\nB is " << b << std::endl;

	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);

	std::cout << "Swap!" <<
		"\nA is " << a << "\nB is " << b << std::endl;	
}

int main()
{
	int iA = 3;
	int iB = 5;
	swap(iA, iB);
	std::getchar();

	std::string sA = "Shilo";
	std::string sB = "Mylo";
	swap(sA, sB);
	std::getchar();

	Cat catA; 
	Cat catB;
	swap(catA, catB); 
	std::getchar();

	//Всё это можно было сделать при помощи одной шаблонной функции
	goodSwap(iA, iB);
	std::getchar();

	goodSwap(sA, sB);
	std::getchar();

	goodSwap(catA, catB);
}