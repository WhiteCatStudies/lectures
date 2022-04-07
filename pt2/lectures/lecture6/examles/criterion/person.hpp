#pragma once
#include <string>
#include <iostream>

class Person 
{
public:
	Person (const std::string& n) : _name(n) 
	{}

	void print () const 
	{
		std::cout << _name << std::endl;
	}

	void print2 (const std::string& prefix) const 
	{
		std::cout << prefix << _name << std::endl;
	}

private:
	std::string _name;
};	