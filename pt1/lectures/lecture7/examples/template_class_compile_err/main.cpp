#include "foo.h"

int main()
{
	// Не скомпилируется: ошибка линкера
	// Компилятор не может найти определение функций-членов класса Foo
	Foo<int> foo(5);
	const int param = foo.getParam();
	
}