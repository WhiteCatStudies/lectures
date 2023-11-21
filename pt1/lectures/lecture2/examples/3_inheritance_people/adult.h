#pragma once
#include <string>

typedef unsigned int uint;

class Adult
{
public:
	Adult(const std::string& name, const std::string& work);
	~Adult();
	void say() const;
	void goWork() const;

	void sayMoney() const;
	void sayEnergy() const;
	void sayTime() const;

private:
	std::string _name;
	std::string _work;

	uint _money;
	uint _energy;
	uint _time;
};

