#include "chunk.h"

#include <cstring> //memcpy
#include <iostream>

Chunk::Chunk(const char* buf, size_t len)
{
	std::cout << "Allocating memory" << std::endl;
	_buf = new char[len];
	_len = len;
	memcpy(_buf, buf, _len);
}

Chunk::~Chunk()
{
	std::cout << "Freeing memory" << std::endl; 
	delete[] _buf;
}