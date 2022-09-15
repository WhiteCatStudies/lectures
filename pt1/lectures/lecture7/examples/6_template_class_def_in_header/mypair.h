#pragma once

#include <iostream>


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

	friend std::ostream& operator<<(std::ostream& os, const MyPair<T, U>& pair)
	{
		os << "(" << pair._first << "; " << pair._second << ")";
		return os;
	};

private:
	T _first;
	U _second;
};
