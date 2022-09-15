#pragma once
#include <string>

class Cat
{
public:
	Cat(const std::string& name, const std::string& breed,
		int mood, int energy, int hunger);
	Cat(const std::string& name);
	// компилятор генерирует определение конструктора по умолчанию
	// Cat::Cat() {...} писать самим уже не надо 
	Cat() = default;

	// в явном виде показывает, что здесь используемтся конструктор копирования
	// генеририруемый компилятором по умолчанию (побитовая копия)  
	Cat(const Cat& other) = default;
	void play();
	void feed();

	int getMood() const;
	int getEnergy() const;
	int getHunger() const;

	friend std::ostream& operator<<(std::ostream& os, const Cat& cat);


private:
	static const int _MAX = 10;	// максимальное значение шкалы настроения, 
								// голода, активности
	static const int _MIN = 0; // минимальное значение шкалы настроения, 
								// голода, активности

	int _mood = 5;	 //настроение. Может меняться от _MIN до _MAX
	int _energy = 5; //активность. Может меняться от _MIN до _MAX
	int _hunger = 5; //голод. Может меняться от _MIN до _MAX

	std::string _breed = "Other"; //порода
	std::string _name;  //имя

	void _meow();
	void _sleep();

	static int _increase(int val);
	static int _decrease(int val);
	static int _validate(int val);
};

