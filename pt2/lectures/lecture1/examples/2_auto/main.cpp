#include <iostream>


void testEasyAuto()
{
	// Проверка простых типов, выведенных auto

	// Не компилируется - переменная не инициализирована,
	// auto неоткуда вывести тип
	// auto a;

	std::cout << "Some easy examples on auto\n";

	auto i = 10;
	std::cout << "auto deduced type for 10: " << typeid(i).name() << '\n';

	auto d = 3.14;
	std::cout << "auto deduced type for 3.14: " << typeid(d).name() << '\n';

	auto ld = 3.14L;
	std::cout << "auto deduced type for 3.14L " << typeid(ld).name() << '\n';

	auto s = "c_string";
	std::cout << "auto deduced type for const char*: " << typeid(s).name() << '\n';
}


void testRefAndConstDeduction()
{
	// Что auto делает с сылками, константами и указателями?
	int x = 100;
	const int y = 200;

	int& rx = x;
	auto a = rx;

	const int& crxy = y;
    auto b = y;

    const int* const ptry = &y;
    auto c = ptry;

    std::cout << "auto deduced type for int&: " << typeid(x).name() << '\n';
    std::cout << "auto deduced type for const int&: " << typeid(y).name() << '\n';
    std::cout << "auto deduced type for const int* const: " << typeid(ptry).name() << '\n';
}


int main()
{
	// Эту программу лучше запускать как ./a.out | c++filt --types
	// typeid(i).name() возвращает некие "коды" для имён типов, 
	// например, PKc - pointer to const char
	// c++filt --types переводит их в более понятный вид
	
	// auto без сюрпризов
	testEasyAuto();
	std::getchar();


	// auto с сюрпризами
	testRefAndConstDeduction();

}