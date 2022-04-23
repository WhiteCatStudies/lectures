#include <iostream>

int main() {
	int* p = new int;
	 std::cout << *p;
	// size_t size;
	// std::cout << "Enter array size" << std::endl;
	// std::cin >> size;

	// // Выелаем массив на стеке: не скомпилируется
	// int p[size];

	// //int *p = new int[size]; // другое дело

	// for (size_t i = 0; i < size; ++i)
	// {
	// 	p[i] = i;
	// }

	// for (size_t i = 0; i < size; ++i)
	// {
	// 	std::cout << p[i] << std::endl;
	// }

	// getchar();

}