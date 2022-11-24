#pragma once

template<class T>
class Add
{
public:
	Add() = default;
	Add(T val): _val(val)
	{}

	void operator()(T& elem)
	{
		elem += _val;
	}

private:
	T _val = 0;
};