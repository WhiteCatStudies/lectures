#include <cstddef>

class Chunk
{
public:
	Chunk(const char* buf, size_t len);
	// Конструктор копирования
	Chunk(const Chunk& other);
	~Chunk();

private:
	char* _buf;
	size_t _len;
};