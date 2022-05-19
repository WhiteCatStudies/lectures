#pragma once

template <class T>
class Foo
{
public:
	Foo(const T& param);
	T getParam() const; 

private:
	T _param;
};
