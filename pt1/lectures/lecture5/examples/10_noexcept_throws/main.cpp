#include <iostream>

void func() noexcept
{
	throw 1;
}

int main()
{
	try
	{
		func();
	}
	catch (int err)
	{
		std::cout << "There is an error: " << err << std::endl;
	}
}