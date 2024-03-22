#pragma once
#include <string>

typedef unsigned int uint;

class Old
{
public:
	Old(const std::string& name);
	~Old();
	void say() const;
	void act() const;

	void sayMoney() const;
	void sayEnergy() const;
	void sayTime() const;

private:
	std::string _name;

	uint _money;
	uint _energy;
	uint _time;
};

