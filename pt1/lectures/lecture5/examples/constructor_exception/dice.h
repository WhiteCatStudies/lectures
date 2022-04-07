#pragma once

typedef unsigned int uint;

class DiceValException
{
};

class Dice
{
public:
	Dice(uint num);
	Dice();
	~Dice();

private:
	uint _val;

	static const uint _MIN;
	static const uint _MAX;
};