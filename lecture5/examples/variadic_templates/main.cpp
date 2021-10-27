#include <iostream>
#include <iomanip>


class Cat
{
};

std::ostream& operator<<(std::ostream& os, const Cat& cat)
{
	os << "Meow!";
	return os;
}

void print ()
{
	// Базовый случай рекурсии
	std::cout << std::endl; 
}

template <typename T, typename... Types>
void print (const T& firstArg, const Types&... args)
{
	// const T& firstArg - первый аргумент
	// const Types&... args - все остальные аргументы
	// Обойти в цикле все аргументы нельзя - нет соответствующего интерфейса
	// Можно только узнать, сколько всего элементов:
	// std::cout << "Elements count is " << (sizeof...(args) + 1) << std::endl; 
	
	// Поэтому рекурсия: первый аргумент печатаем сразу, а все остальные передаём в следующий
	// вызов print. Там они снова распакуются: первый агрумент из const Types&... args
	// станет T& firstArg и так далее
	std::cout << firstArg << " "; 
	print(args...);
}


template <class T1, class T2>
bool isOneOf(T1&& a, T2&& b) 
{
	std::cout << "Comparing " << a << " and " << b << std::endl;
	return a == b;
}

template <class T1, class T2, class... Ts>
bool isOneOf(T1&& a, T2&& b, Ts&&... vs) 
{
	std::cout << "Comparing " << a << " and " << b << std::endl;
	return a == b || isOneOf(a, vs...);
}

int main()
{
	print("Anna", 3.1415, 42, Cat(), "This is serious!");
	print("The highest mountain in the world is", 8848, "meters heigh");
	std::getchar();

	std::cout << "Is there \"1\" among \"2, 3.5, 4, 1, 2\"?" << std::endl;
	std::cout << std::boolalpha << isOneOf(1, 2, 3.5, 4, 1, 2) << std::endl;
}