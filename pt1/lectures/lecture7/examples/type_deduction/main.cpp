#include <iostream>
#include <string>

template <class T>
void printUninit()
{
	T smth;
	std::cout << "\"" << smth << "\"" << std::endl; 	
}

template <class T>
T sum(T first, T second)
{
	return first + second;
}

int main()
{
	// Если шаблонная функция имеет параметры обобщённых типов, как правило,
	// компилятор может сам вывести тип.
	// Но иногда ему всё же нужна помощь. Например, если параметров обобщённого типа нет,
	// нужно задавать тип явно при вызове функции

	// Не скомпилируется: couldn’t deduce template parameter ‘T’
	//printUninit();
	printUninit<int>();
	printUninit<long>();
	printUninit<double>();
	printUninit<float>();
	printUninit<std::string>();
	std::getchar();

	// Иногда необходимо "навязать" преобразование типов
	// Не скомпилируется, т.к. aргументы имеют тип const char*, 
	// для которого не определён оператор сложения  
	// sum("Hello ", "World");
	std::cout << sum<std::string>("Hello ", "World") << std::endl;
	std:getchar();

	// Компилятор также не сможет вывести тип, 
	// если шаблонная функция принимает два одинаковых типа, 
	// а мы передаём ей параметры разных типов
	int a = 10;
	long b = 20;
	// Не скомпилируется: deduced conflicting types for parameter ‘T’ (‘int’ and ‘long int’)
	//sum(a, b);
	std::cout << sum<long>(a, b) << std::endl;
	std::cout << sum<int>(a, b) << std::endl;
}