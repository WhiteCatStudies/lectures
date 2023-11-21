// Этот пример не компилируется из-за рекурсивного включения заголовков
// fridge_raider.h и home.h
#include <string>  


class Fridge
{
public:
	Fridge(size_t size);
	~Fridge();

	void put(const std::string& food);
	std::string get();

private:
	std::string* _food;
	size_t _size;
	size_t _index;
};
