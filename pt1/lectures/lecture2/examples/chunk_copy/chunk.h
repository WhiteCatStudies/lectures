#include <cstddef>

class Chunk
{
public:
	Chunk(const char* buf, size_t len);
	~Chunk();

private:
	char* _buf;
	size_t _len;
};