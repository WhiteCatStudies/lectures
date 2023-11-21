/*
https://itnext.io/c-20-concepts-complete-guide-42c9e009c6bf
https://www.cppstories.com/2021/concepts-intro/
*/

#include <string>
#include <concepts>
#include <iostream>

#include "person.h"
#include "box.h"


void funcWithoutConcept(const auto& x) 
{
    std::string v = x;
}

// Вообще у std::convertible_to два параметра - что преобразуется к чему, - 
// но в варианте с auto один из них выводится 
void funcWithConcept(const std::convertible_to<std::string> auto& x) 
{
    std::string v = x;
}

// Другие варианты синтаксиса
void funcWithConceptRequired(const auto& x)
    requires std::convertible_to<decltype(x), std::string> 
{
    std::string v = x;
}

template <std::convertible_to<std::string> T>
void funcWithTemplateInline(const T& x) 
{
    std::string v = x;
}

template <typename T>
requires std::convertible_to<T, std::string>
void funcWithTemplatePostfix(const T& x) 
{
    std::string v = x;
}

template <typename T>
requires std::integral<T> ||
	(std::invocable<T> &&
 	 std::integral<typename std::invoke_result<T>::type>)
void function(const T& x) 
{
	//if constexpr - compile time if
    if constexpr (std::invocable<T>) 
    {
        std::cout << "Result of call is " << x() << "\n";
    } 
    else 
    {
        std::cout << "Value is " << x << "\n";
    }
}

void testComplexConcepts()
{
    function(1); // OK, integral
    function([]() { return 2; }); // OK, invocable, returns integral
    // function(2.0); // Fails
}


template<typename T>
concept hasStringName = requires(T v) 
{ 
    { v.name } -> std::convertible_to<std::string>; 
};

void printName(const hasStringName auto& obj)
{
	std::cout << "The function with concept says:\nThe name is " << 
		obj.name << "\n";
}


int main() 
{
	// В данном случае использование концепта 
	// даёт более информативное сообщение об ошибке компиляции 
    // funcWithoutConcept(1);
    // funcWithConcept(1);

	testComplexConcepts();

	// ОК - у структуры Person есть член данных name, 
	// который можно представить как std::string
	printName(Person{"Anna", "Enginner", true});

	// Не ОК - .\main.cpp:76:6: note: constraints not satisfied
	// .\main.cpp: In substitution of 'template<class auto:14>  requires  hasStringName<auto:14>
	// У структуры Box нет такого члена данных
	// printName(Box{2.5, false});
}