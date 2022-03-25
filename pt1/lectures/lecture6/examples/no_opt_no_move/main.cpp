#include <vector>
#include <iostream>

void printVector(const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << "; ";
	}

	std::cout << std::endl;
}

void mulTwoOldsyle(const std::vector<int>& source, std::vector<int>& dest)
{
	//До появления семантики перемещения и обязательных оптимизаций
	//стоило избегать возвращаемых значений сложных типов во избежание копирования. 
	//Результат передавался по неконстантной ссылке и модифицировался внутри функции
	const size_t sourceSize = source.size();
	dest.resize(sourceSize);

	for (size_t i = 0; i < sourceSize; ++i)
	{
		dest[i] = source[i] * 2;
	}
}

std::vector<int> mulTwo(const std::vector<int>& source)
{
	// Начиная с C++ 11 можно смело возвращать такие объекты из функций
	// т.к. они или будут сконструированы на стеке вызывающей функции или 
	// перемещены   
	std::vector<int> dest;
	const size_t sourceSize = source.size();
	dest.resize(sourceSize);

	for (size_t i = 0; i < sourceSize; ++i)
	{
		dest[i] = source[i] * 2;
	}

	return dest;
}

int main()
{
	std::vector<int> source = { 1, 2, 3, 4, 5, 6, 7 };
	std::cout << "Initial vector is: " << std::endl; 
	printVector(source);

	// Oldstyle-версия
	std::cout << "Testing old-style function" << std::endl;
	std::vector<int> dest;
	mulTwoOldsyle(source, dest);
	printVector(dest);
	std::getchar();

	std::cout << "Testing modern version" << std::endl;
	printVector(mulTwo(source));
}