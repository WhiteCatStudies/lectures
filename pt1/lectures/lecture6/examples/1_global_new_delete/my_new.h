#pragma once
#include <cstdlib>
#include <iostream>
#include <new>


static std::size_t alloc{0};
static std::size_t dealloc{0};

void* operator new(std::size_t sz) noexcept
{
    alloc += 1;
    return std::malloc(sz);
}

void* operator new[](size_t sz) noexcept
{
    alloc += 1;
    return std::malloc(sz);
}

void operator delete(void* ptr) noexcept
{
    dealloc += 1;
    std::free(ptr);
}

void operator delete[](void* ptr) noexcept
{
    dealloc += 1;
    std::free(ptr);
}

void getInfo()
{
    std::cout << "Number of allocations: " << alloc << std::endl;
    std::cout << "Number of deallocations: " << dealloc << std::endl;   
}
