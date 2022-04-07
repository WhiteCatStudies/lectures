#include <iostream>

#define MY_FAVORITE_NUMBER 9

int main()
{
	// Вместо каждого вхождения MY_FAVORITE_NUMBER в исходный код 
	// после препроцессинга будет подставлено значение 9
	std::cout << "My favorite number is: " << MY_FAVORITE_NUMBER << std::endl;
}