#pragma once
#include <string>  
#include <iostream>

class Fridge
{
public:
	Fridge(size_t size);
	// конструктор копирования
	Fridge(const Fridge& other);
	// конструктор перемещения принимает параметр 
	// по неконстантной rvalue-ссылке 
	Fridge(Fridge&& other);
	~Fridge();

	// оператор копирующего присваивания (copy assignment)
	Fridge& operator=(const Fridge& other);

	// оператор перемещающего присваивания (move assignment)
	Fridge& operator=(Fridge&& other);

	void put(const std::string& food);
	std::string get();

	static void printOpCount();

private:
	// Эти счётчики нужны для демонстрации операций
	// копирования/перемещения, имеющих сторонние эффекты (плохая идея) 
	static size_t _copyCount;
	static size_t _moveCount; 

	std::string* _food;
	size_t _size;
	size_t _index;
};