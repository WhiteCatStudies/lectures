#pragma once

#include <string>
#include <iostream>

class Vector
{
public:
	Vector(int x, int y);
	Vector();
	Vector(const Vector& other);

	// перегрузка бинарных операторов
	// other - правый операнд. Левый - неявно передаваемый this
	// правый операнд операторами сравнения, сложения и копирующего присваивания
	// не должен изменяться, поэтому он передаётся по константной ссылке
	// оператор сравнения возвращает bool: либо равно, либо нет
	bool operator==(const Vector& other);

	// оператор сложения возвращает новый объект 
	Vector operator+(const Vector& other);
	
	// оператор копирующего присваивания возвращает ссылку на присваиваемый объект.
	// возвращение копии присваиваемого объекта не приводит к ошибкам
	// Однако, благодаря возвращению ссылки, возможны конструкции типа v1 = v2 = v3
	Vector& operator=(const Vector& other);

	// перегрузка унарных операторов
	// префиксный инкремент/декремент
	Vector& operator++();
	Vector& operator--();
	// перегрузка с помощью функции-"друга": передаем вектор в явном виде. Но зачем?
	// friend Vector operator++(Vector& vec);

	// постфиксный инкремент/декремент
	// параметр notUsed нигде не используется. Он служит для того, чтобы компилятор 
	// мог отличать префиксную и постфиксную формы
	Vector operator++(int notUsed);
	Vector operator--(int notUsed);
	// friend Vector operator++(Vector& vec, int notUsed);

	// сможет обработать coeff * 2, но не 2 * coeff, так как параметр типа Vector
	// должен всегда передаваться первым    
	Vector operator*(int coeff);
	// функции-"друзья" не зависят от порядка параметров
	friend Vector operator*(int coeff, const Vector& vec);

	// аналогично перегрузка оператора вставки в поток должна быть "другом"
	// т. к. она долдна получать объект потока первым аргументом
	friend std::ostream& operator<<(std::ostream& os, const Vector& vec);

private:
	int _x;
	int _y;
};