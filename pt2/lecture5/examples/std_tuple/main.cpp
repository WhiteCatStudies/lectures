#include <tuple>
#include <iostream>
#include <string>
#include <typeinfo>


template <class T>
void printWithType(T val)
{
	std::cout << "Type: " << typeid(T).name() << "; Value: " << val << std::endl;
}

int main()
{
	std::cout << "Testing std::tuple" << std::endl;
	std::tuple<int, float, std::string> t1(41, 6.3, "nico");
	std::cout << std::get<0>(t1) << " " << std::get<1>(t1) << " " << 
		std::get<2>(t1) << " " << std::endl;
	std::getchar();

	// Создание кортежа с std::make_tuple 
	auto t2 = std::make_tuple(22, 44, "nico");

	// Переприсваивание включает изменение типа
	std::cout << "Before reassignment" << std::endl; 
	printWithType(std::get<2>(t1));
	
	std::get<1>(t1) = std::get<2>(t1);
	printWithType(std::get<1>(t1));
}