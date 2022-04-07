#pragma once

#include "list.h"

// Стэк: первым пришёл, первым ушёл
// Стек хранит данные во вспомогательном контейнере
// По умолчанию это список, но может быть и любой другой шаблонный тип:
// вектор, дека и тд
// если бы не шаблонный формальный параметр, т.е если бы он был не
// template<class> class Cont, а просто class Cont, были бы возможны ситуации типа:
// Stack<int, List<std::string>> 
template <class T, template<class> class Cont = List>
class Stack
{
	Cont<T> _cont;

public:
	void push(T data)
	{
		_cont.pushFront(data);
	}

	T pop()
	{
		return _cont.popFront();
	}

	bool empty() const
	{
		return _cont.empty();
	}
};