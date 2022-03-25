#pragma once
#include <string>

typedef unsigned int uint;

class Person
{
public:
	Person(const std::string& name,
		uint money, uint energy, uint time);
	virtual ~Person();
	virtual void say() const = 0;

	void sayMoney() const;
	void sayEnergy() const;
	void sayTime() const;

protected:
	std::string _name;

	uint _money;
	uint _energy;
	uint _time;

	static const uint _MIN = 0;
	static const uint _MAX = 100;
};

