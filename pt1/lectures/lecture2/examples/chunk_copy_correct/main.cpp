#include "chunk.h"

int main()
{
	char buf[125] = {0};
	for (int i = 0; i < 125; ++i)
	{
		buf[i] = i;
	}

	Chunk chunk = Chunk(buf, 125);
	Chunk anotherChunk = chunk;
}