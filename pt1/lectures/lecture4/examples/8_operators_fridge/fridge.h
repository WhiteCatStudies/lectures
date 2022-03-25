#pragma once
#include <string>  
#include <iostream>

class Fridge
{
public:
	Fridge(size_t size);
	Fridge(const Fridge& other);
	~Fridge();

	// оператор копирующего присваивания
	Fridge& operator=(const Fridge& other);

	// оператор индексирования
	std::string& operator[](int index);

	// оператор вызова функции
	// может использвоаться для программирвоания в функциональном стиле
	std::string operator()();

	void put(const std::string& food);
	std::string get();

private:
	std::string* _food;
	size_t _size;
	size_t _index;
};

// оператор извлечения из потока не должен быть "другом"
// он не использует закрытые члены класса 
std::istream& operator>>(std::istream& is, Fridge& fridge);