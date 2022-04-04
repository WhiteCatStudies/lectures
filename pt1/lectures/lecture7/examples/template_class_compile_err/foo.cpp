#include "foo.h"

template <class T>
Foo<T>::Foo(const T& param): _param(param)
{
}

template<class T> 
T Foo<T>::getParam() const
{
	return _param;
}

// Создание специализации Foo<int> во время компиляции
// Если тип Foo<int> определён, ошибки линкера не будет
template<> class Foo<int>;