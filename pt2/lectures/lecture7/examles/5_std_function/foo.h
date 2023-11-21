#pragma once
#include <iostream>


struct PrintNum 
{
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

struct Foo 
{
    Foo(int num_): num(num_)
    {}
    
    void printAdd(int i) const 
    {
    	std::cout << num + i << '\n'; 
    }

    int num;
};
