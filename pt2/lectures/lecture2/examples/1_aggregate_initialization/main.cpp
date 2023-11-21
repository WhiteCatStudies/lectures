#include <iostream>

struct Aggregate
{
	int a;
	int b;
	int arr[2];
	std::string c;

	void print()
	{
		std::cout << "a = " << a << "; b = " << b << "; c = " << c <<
			"; arr = [" << arr[0] << ", " << arr[1] << "]" << std::endl;
	}

private:
	void info()
	{
		std::cout << "Private functions do no violate aggregate rules!" << std::endl; 
	};
};

int main()
{
	// struct Aggregate удовлетворяет условиям составного типа:
	Aggregate example{1, 2, {10, 15}, "example"};
	example.print();

	Aggregate test = {3, 4, {10, 20}, "test"}; 
	test.print();

	// Ошибка: designator order does not match declaration order
	//Aggregate cpp20Syntax = {.a = 5, .b = 6, .c = "new", .arr = {30, 40}};
	Aggregate cpp20Syntax = {.a = 5, .b = 6, .arr = {30, 40}, .c = "new",};
	cpp20Syntax.print(); 
}