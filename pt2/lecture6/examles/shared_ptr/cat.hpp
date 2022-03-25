#pragma once
#include <string>

class Cat
{
public:
	Cat(const std::string& name, const std::string& breed,
		int mood, int energy, int hunger);
	Cat();
	~Cat();
	void play();
	void feed();

	int getMood() const;
	int getEnergy() const;
	int getHunger() const;

	std::string getName() const;

private:
	static const int _MAX;	// максимальное значение шкалы настроения, 
							// голода, активности
	static const int _MIN;  // минимальное значение шкалы настроения, 
							// голода, активности

	int _mood;	//настроение. Может меняться от _MIN до _MAX
	int _energy; //активность. Может меняться от _MIN до _MAX
	int _hunger; //голод. Может меняться от _MIN до _MAX

	std::string _breed; //порода
	std::string _name;  //имя

	void _meow();
	void _sleep();

	static int _increase(int val);
	static int _decrease(int val);
	static int _validate(int val);
};

