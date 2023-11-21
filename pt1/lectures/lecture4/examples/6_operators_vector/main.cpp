#include "2d_vector.h"

#include <iostream>
#include <string>


void printPair(const std::pair<int, int>& p)
{
	std::cout << "first: " << p.first << "; second: " << p.second << "\n"; 
}

int main()
{
	std::cout << "First vector:\n";
	Vector first(3, 4);
	std::cout << "Second vector:\n";
	Vector second(10, 20);
	std::getchar();

	std::cout << "Sum of the vectors\n";
	Vector sum  = first + second;
	std::getchar();

	std::cout << "Comparing vectors\n";
	const std::string isEqual = (first == second ? "yes": "no");
	std::cout << "Are the vectors equal? " << isEqual << "\n";
	std::getchar();

	// При присваивании объекту, который до присваивания не существовал, 
	// вызывается конструктор копирования. Оператор копирующего присваивания 
	// вызывался бы из левого операнда, а левый операнд ещё не создан
	std::cout << "Assigning first vector to another new vector\n";
	Vector another = first;
	std::cout << "New vector: " << another << "\n";
	std::getchar();

	// При присваивании уже существующему объекту 
	// вызывается его оператор копирующего присваивания. 
	// Потом значение, возвращаемое оператором копирующего присваивания,  
	std::cout << "Assigning second vector to previously defined vector\n";
	another = second;
	std::getchar();

	// Префиксный инкременты/декремент: значение изменяется сразу 
	std::cout << "Assign pre-incremented first vector to new vector\n";
	Vector preIncremented = ++first;
	std::cout << "New vector is: " << preIncremented << "\n";
	std::cout << "First vector is: " << first << "\n";
	std::getchar();

	// Постфиксный инкременты/декремент: значение сначала используется в выражении,
	// а потом уже изменяется 
	std::cout << "Assign post-incremented second vector to new vector\n";
	Vector postIncremented = second++;
	std::cout << "New vector is: " << postIncremented << "\n";
	std::cout << "Second vector is: " << second << "\n";
	std::getchar();

	std::cout << "Assigning to new vector first vector multiplyed by 2\nvector * coeff\n";
	// сможет вызвать оператор умножения из класса Vector
	Vector multiplyed = first * 2;
	std::cout << "The new vector is " << multiplyed << "\n";
	std::getchar();

	std::cout << "coeff * vector\n";
	// такой оператор не может быть реализован в классе Vector,
	// но может быть его "другом"
	Vector friendMultiplied = 2 * first;
	std::cout << "The new vector is " << friendMultiplied << "\n";
	std::getchar();	

	if(first)
	{
		std::cout << "Vector " << first << " is not empty\n";
	}

	std::getchar();
	printPair(first);
}