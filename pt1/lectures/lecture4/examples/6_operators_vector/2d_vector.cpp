#include "2d_vector.h"

#include <sstream>

Vector::Vector(int x, int y): _x(x), _y(y)
{
	std::cout << "Parameterized constructor: " << *this << "\n"; 
}

Vector::Vector(): _x(0), _y(0)
{
	std::cout << "Default constructor: " << *this << "\n";
}

Vector::Vector(const Vector& other)
{
	std::cout << "Copy construction from " << other << "\n"; 
	_x = other._x;
	_y = other._y;
}

Vector Vector::operator+(const Vector& other)
{
	std::cout << "Calling operator+ from vector: " << *this << "\n";
	// операция сложения не изменяет ни одного из своих операндов
	// и возвращает новый объект 
	return Vector(_x + other._x, _y + other._y); 
}

Vector& Vector::operator=(const Vector& other)
{
	std::cout << "Calling operator= from vector: " << *this << "\n";
	_x = other._x;
	_y = other._y;
	// операция копирующего присваивания изменяет объект, стоящий слева от операнда
	// и возвращает его копию
	std::cout << "Assignment done. The vector is: " << *this << " now\n";
	return *this;
}

bool Vector::operator==(const Vector& other)
{
	// операция сравнения не изменяет ни одни из своих операндов 
	// и возвращает булево значение (либо равно, либо не)
	std::cout << "Calling comparion operator from vector: " << *this << "\n";
	return _x == other._x && _y == other._y;
}

Vector& Vector::operator++()
{
	std::cout << "Calling pre-increment from vector: " << *this << "\n";
	++_x;
	++_y;
	return *this;
}

Vector& Vector::operator--()
{
	std::cout << "Calling pre-decrement from vector: " << *this << "\n"; 
	--_x;
	--_y;
	return *this;
}

Vector Vector::operator++(int notUsed)
{
	std::cout << "Calling post-increment from vector: " << *this << "\n"; 
	Vector tmp = *this;
	++_x;
	++_y;
	return tmp;
}

Vector Vector::operator--(int notUsed)
{
	std::cout << "Calling post-decrement from vector: " << *this << "\n"; 
	Vector tmp = *this;
	--_x;
	--_y;
	return tmp;
}

Vector Vector::operator*(int coeff)
{
	std::cout << "Calling multipliation operator from vector: " << *this << "\n"; 
	return Vector(coeff * _x, coeff * _y);
}

Vector operator*(int coeff, const Vector& vec)
{
	std::cout << "Calling multipliation operator from friend function\n";
	return Vector(coeff * vec._x, coeff * vec._y);
}

Vector::operator bool() const
{
	std::cout << "Calling type cast to bool\n";
	return (_x != 0) && (_y != 0);
}

Vector::operator std::pair<int, int>() const
{
	std::cout << "Calling cast to std::pair\n";
	return std::pair<int, int>(_x, _y);
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
	os << "{" << vec._x << "; " << vec._y << "}";
	return os;
}
