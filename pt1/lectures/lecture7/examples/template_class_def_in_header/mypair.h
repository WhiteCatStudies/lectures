#pragma once

#include <iostream>

// Вариант (1) решения проблемы с ошибкой линкера при использовании функций-друзей
// шаблонного класса
// Опережающее объявление (forward declaration) шаблонного класса MyPair
// template <class T, class U> class MyPair;
// Еще раз показываем компилятору, что operator<< - шаблон 
// template <class T, class U>
// std::ostream& operator<<(std::ostream& os, const MyPair<T, U>& pair);

template <class T=int, class U=int>
class MyPair
{
public:
	MyPair(const T& first, const U& second) :
		_first(first), _second(second)
		{};

	MyPair() 
	{
		_first = T();
		_second = U();
	};

	static MyPair makePair(const T& first, const U& second)
	{
		return MyPair(first, second);
	};

	T getFirst() const
	{
		return _first;
	};

	U getSecond() const	
	{
		return _second;
	};

	// компилятор не знает, что operator<< - шаблонная функция
	// Линкер будет искать нешаблонный operator<< и не найдёт
	//friend std::ostream& operator<<(std::ostream& os, const MyPair<T, U>& pair);

	// Вариант решения (1): 
	// Показываем, что operator<< - шаблон: operator<< <> и см. выше 
	//friend std::ostream& operator<< <>(std::ostream& os, const MyPair<T, U>& pair);

	// Вариант решения (2):
	// определяем operator<< прямо тут
	friend std::ostream& operator<<(std::ostream& os, const MyPair<T, U>& pair)
	{
		os << "(" << pair._first << "; " << pair._second << ")";
		return os;
	};

private:
	T _first;
	U _second;
};

// Определение шаблонной функции-оператора вставки в поток к варианту (1)
/*
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const MyPair<T, U>& pair)
{
	os << "(" << pair._first << "; " << pair._second << ")";
	return os;
}
*/