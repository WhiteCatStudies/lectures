#pragma once
#include <iostream>
#include <string>

class Base
{
public:
	Base() = default;
	virtual std::string say() const
	{
		return "I am Base";
	}

	virtual ~Base() = default;
};

std::ostream& operator<<(std::ostream& os, const Base& b)
{
	os << b.say();
	return os;
} 


class Derived : public Base
{
public:
	Derived() = default;

	std::string say() const override
	{
		return "I am Derived";
	}

	virtual ~Derived() = default;
};

std::ostream& operator<<(std::ostream& os, const Derived& d)
{
	os << d.say();
	return os;
}


class NoOnesRelative
{
public:
	NoOnesRelative() = default;

	std::ostream& operator<<(std::ostream& os)
	{
		os << "I am Noones reletive";
		return os;
	}
};