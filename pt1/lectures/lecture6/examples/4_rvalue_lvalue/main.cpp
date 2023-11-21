#include <iostream>

int getRVal() 
{
	return 2;
}

int x = 10;

int& getLVal()
{
	return x;
}

void printVal(int& a)
{
	std::cout << "Print passed by non-const lvalue ref: " << a << std::endl;
}

void printConstVal(const int& a)
{
	std::cout << "Print passed by const lvalue ref: " << a << std::endl;
}

void incr(int& a)
{ 
	++a;
}

int main()
{
	// a - lvalue, 5 - rvalue
	int a = 5;
	int* ptrA = &a;

	// Наоборот не работает (не новость): 
	// по левую сторону присваивания может быть только lvalue
	// 5 = a;
	// Нельзя получить адрес rvalue по lvalue-ссылке
	// int* rPtr = &5;

	// lvalue может неявно конвертироваться в rvalue, но не наоборот
	// a справа от знака равенста, но а - lvalue
	int b = a;
	// b - lvalue, но оператор взятия адреса возвращает rvalue. 
	int* ptrB = &b;
	// a и b - lvalue, но оператор "+" принимает rvalue 
	// промежуточные результаты арифметических операторов (a + b) - тоже rvalue
	int c = b + a + 15;

	// преинкремент - lvalue
	int* preIncrPtr = &(++a);
	// не скомпилируется: постинкремент - rvalue
	//int* postIncrPtr = &(a++);

	// Несмотря на то, что строковые литералы могут стоять
	// только справа от знака равенства, это lvalue, 
	// т.к. они представляют собой массив в памяти, следовательно, имеют адрес
	// остальные литералы (42, true, nullptr) - rvalue
	const char* hello = "Hello";

	// a - lvalue, поэтому его можно передавать как по константной,
	// так и по неконстантной ссылке
	printVal(a);
	printConstVal(a);

	// Можно передать по константной ссылке
	printConstVal(5);
	// Не скомпилируется - изменять временные объекты нельзя (и бессмысленно),
	// поэтому их запрещено передавать по неконстантной ссылке
	// printVal(5);
	// Если бы было можно, функция incr или бессмысленно увеличивала бы 
	// что-то временное или превращала бы 0 в 1
	// incr(0);
	// Также не скомпилируется:
	//int& nonConstRRef = 5; 
	// А вот так можно:
	const int& constRRef = 5; 

	// getLVal возвращает lvalue, поэтому вывоз getLVal может стоять 
	// по обе стороны присваивания 
	getLVal() = 3;
	int x = getLVal();

	// getRVal возвращает rvalue и может стоять только справа
	int y = getRVal();
	// неа
	// getRVal() = 4;
}	