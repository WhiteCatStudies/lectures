#pragma once
#include <iostream>
#include <string> 


class A
{
public:
    A() = default;
    A(const std::string& v) : _val(v)
    {}

private:
	std::string _val;

public:
    auto getLambda() const
    {
		// Нам нужно "захватить" this, потому что нужен доступ к членам класса
		// Однако, this - указатель, и, когда функция завершится, 
		// объект, на который он указывает, выйдет из области видимости,
		// и указатель инвалидируется.
		// Захват [*this] вместо [this] позволяет избежать данной проблемы, т.к.
		// это - захват копии
		return [*this]() { std::cout << "My value is " << _val << std::endl; };
	}
};

std::ostream& operator<<(std::ostream& os, const A& a)
{
	os << "I am A";
	return os; 
}
 
class B : public A
{
public:
    B() = default;
};
 
std::ostream& operator<<(std::ostream& os, const B& b)
{
	os << "I am B";
	return os; 
}

class C : public A
{
public:
    C() = default;
};

std::ostream& operator<<(std::ostream& os, const C& c)
{
	os << "I am C";
	return os; 
}