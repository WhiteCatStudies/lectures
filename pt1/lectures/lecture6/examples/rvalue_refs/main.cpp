#include <string>
#include <iostream>

void printRef(const std::string& s)
{
	// Принимает как lvalue, так и rvalue
	std::cout << "By lvalue reference: " << s << std::endl;
}

void printRef(std::string&& s)
{
	// Принимает только rvalue 
	std::cout << "By rvalue reference: " << s << std::endl;
}

int main()
{
	// Только константная lvalue-ссылка может ссылаться на временный объект - 
	// временные объекты нельзя изменять
	//int& x = 2;
	const int& x = 2;
	// неконстантная rvalue-ссылка позволяет сослаться на временный объект
	// и изменять его
	int&& y = 4;
	++y;
	std::cout << "y = " << y << std::endl;
	std::getchar();

	// rvalue-ссылки могут быть константными, но на практике это используется редко
	const int&& r = 10;

	std::string s1 = "Hello, ";
	std::cout << "s1 is " << s1 <<std::endl;

	std::string s2 = "world!";
	std::cout << "s2 is " << s2 << std::endl;

	// Оператор сложения возвращает rvalue
	// Не скомпилируется: нельзя получить адрес rvaue с помощью lvalue-ссылки
	// std::string& sum = (s1 + s2);

	// А вот с помощью rvalue-cсылки можно
	std::string&& sum = s1 + s2;
	std::cout << "s1 + s2 = " << sum << std::endl; 
	std::getchar();

	std::cout << "Lets add somethig by rvalue reference" << std::endl;
	sum += " Rvalue references are cool";
	std::cout << "And now the sum is: " << sum << std::endl;
	std::getchar();

	// Не компилируется - rvalue-ссылки могут ссылаться только на rvalue 
	//int y = 11;
	//int&& ref = y;

	// За счёт этого можно использовать ralue-ссылки, 
	// чтобы отличать временные объекты от постоянных
	const std::string name = "Anna";
	printRef(name);
	printRef("Wasia");
	// nameRef представляет собой rvalue-ссылку на std::string, 
	// но сам nameRef - lvalue, т.к. он имеет адрес (не временный объект) 
	// и стоит слева от знака равенства
	std::string&& nameRef = "Igor";
	printRef(nameRef);
}