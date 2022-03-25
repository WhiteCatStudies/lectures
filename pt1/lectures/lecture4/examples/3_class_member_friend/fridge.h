#include <string>  


class Fridge
{
public:
	Fridge(size_t size);
	// класс управляет динамически выделенной памятью - 
	// необходим конструктор копирования
	Fridge(const Fridge& other);
	~Fridge();

	void put(const std::string& food);
	std::string get();

private:
	std::string* _food;
	size_t _size;
	size_t _index;
};