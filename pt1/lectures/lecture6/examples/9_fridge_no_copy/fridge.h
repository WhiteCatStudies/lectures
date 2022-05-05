#pragma once
#include <string>  
#include <iostream>

class Fridge
{
public:
	Fridge(size_t size);
	// конструктор копирования удалён - нельзя копировать холодильники!
	// До С++ 11 методы, использование которых требовалось запретить,
	// объявляли как private 
	Fridge(const Fridge& other) = delete;

	// конструктор перемещения 
	Fridge(Fridge&& other);
	~Fridge();

	// оператор копирующего присваивания (copy assignment) удален
	Fridge& operator=(const Fridge& other) = delete;

	// оператор перемещающего присваивания (move assignment)
	Fridge& operator=(Fridge&& other);

	void put(const std::string& food);
	std::string get();

	static void printOpCount();
	friend std::ostream& operator<<(std::ostream& os, const Fridge& fridge);

private:
	// Эти счётчики нужны для демонстрации операций
	// копирования/перемещения, имеющих сторонние эффекты (плохая идея) 
	static size_t _copyCount;
	static size_t _moveCount; 

	std::string* _food;
	size_t _size;
	size_t _index;
};