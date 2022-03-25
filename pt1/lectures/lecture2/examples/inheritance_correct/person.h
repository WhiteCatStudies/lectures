#pragma once
#include <string>

typedef unsigned int uint;

class Person
{
public:
	Person(const std::string& name,
		uint money, uint energy, uint time);
	void say() const;

	void sayMoney() const;
	void sayEnergy() const;
	void sayTime() const;

protected:
//private:
	std::string _name;

	uint _money;
	uint _energy;
	uint _time;

	static const uint _MIN = 0;
	static const uint _MAX = 100;
};

