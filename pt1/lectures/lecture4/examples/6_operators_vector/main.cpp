#include "2d_vector.h"

#include <iostream>
#include <string>

int main()
{
	std::cout << "First vector:" << std::endl;
	Vector first(3, 4);
	std::cout << "Second vector:" << std::endl;
	Vector second(10, 20);
	getchar();

	std::cout << "Sum of the vectors" << std::endl;
	Vector sum  = first + second;
	getchar();

	std::cout << "Comparing vectors" << std::endl;
	const std::string isEqual = (first == second ? "yes": "no");
	std::cout << "Are the vectors equal? " << isEqual << std::endl;
	getchar();

	// При присваивании объекту, который до присваивания не существовал, 
	// вызывается конструктор копирования. Оператор копирующего присваивания 
	// вызывался бы из левого операнда, а левый операнд ещё не создан
	std::cout << "Assigning first vector to another new vector" << std::endl;
	Vector another = first;
	std::cout << "New vector: " << another << std::endl;
	getchar();

	// При присваивании уже существующему объекту 
	// вызывается его оператор копирующего присваивания. 
	// Потом значение, возвращаемое оператором копирующего присваивания,  
	std::cout << "Assigning second vector to previously defined vector" << std::endl;
	another = second;
	getchar();

	// Префиксный инкременты/декремент: значение изменяется сразу 
	std::cout << "Assign pre-incremented first vector to new vector" << std::endl;
	Vector preIncremented = ++first;
	std::cout << "New vector is: " << preIncremented << std::endl;
	std::cout << "First vector is: " << first << std::endl;
	getchar();

	// Постфиксный инкременты/декремент: значение сначала используется в выражении,
	// а потом уже изменяется 
	std::cout << "Assign post-incremented second vector to new vector" << std::endl;
	Vector postIncremented = second++;
	std::cout << "New vector is: " << postIncremented << std::endl;
	std::cout << "Second vector is: " << second << std::endl;
	getchar();

	std::cout << "Assigning to new vector first vector multiplyed by 2" << std::endl;
	std::cout << "vector * coeff" << std::endl;
	// сможет вызвать оператор умножения из класса Vector
	Vector multiplyed = first * 2;
	std::cout << "The new vector is " << multiplyed << std::endl;
	getchar();

	std::cout << "coeff * vector" << std::endl;
	// такой оператор не может быть реализован в классе Vector,
	// но может быть его "другом"
	Vector friendMultiplied = 2 * first;
	std::cout << "The new vector is " << friendMultiplied << std::endl;
}