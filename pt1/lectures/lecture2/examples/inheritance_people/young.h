#pragma once
#include <string>

typedef unsigned int uint;

class Young
{
public:
	Young(const std::string& name);
	~Young();
	void say() const;
	void saySmthCool() const;
	void goStudy() const;

	void sayMoney() const;
	void sayEnergy() const;
	void sayTime() const;

private:
	std::string _name;
	
	uint _money;
	uint _energy;
	uint _time;

	static const uint _MIN = 0;
	static const uint _MAX = 100;
};

