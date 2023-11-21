#include <iostream>
#include <iomanip>
#include <string>

#include "some_classes.h"


void easyStaticCast()
{
	std::cout << "Test some easy type casts\n";

	int a = 10;
	int b = 4;

	double res1 = a / b;
	// результат деления a / b - целое число, т.к. а - целое число
	// дальше этот результат преобразуется в double, чтобы его можно было хранить в res1,
	// но дробная часть уже была отброшена при целочисленном делении
	std::cout << std::fixed << "No cast: the result is: " << res1 << '\n';

	double res2 = (double)a / b;
	// здесь выглядит безобидно, но на самом деле C-style cast очень коварен
	// лучше не использовать его просто на всякий случай,
	// а ещё во имя чистоты кода - мы пишем на C++, а не на C
	std::cout << "C-style cast: the result is: " << res2 << '\n';

	double res3 = static_cast<double>(a) / b;
	std::cout << "static_cast: the result is: " << res2 << '\n';	
}

void evilCStyleCast()
{
	// Тип размером 1 байт
	char c = 10;

	// Приводим указатель на тип размером 1 байт к указателю на тип размером 4 байта
	// Компилятор всё устраивает - он молчит  
	int *p = (int*)&c;

	// Пишем по этому указателю значение, которое не поместится в 1 байт
	// Портим память на стеке, долго ищем злую ошибку
	*p = 400;
	std::cout << "The value is: " << *p << '\n';

	// А вот это бы не скомпилировалось,
	// что изначально заставило бы нас искать более адекватное решение
	// int *sp = static_cast<int*>(&c);
	// error: invalid 'static_cast' from type 'char*' to type 'int*'
    // 		int *sp = static_cast<int*>(&c);
}

void staticCastInheritance()
{
	std::cout << "Test type casting in case of inheritance\n";
	Base *b = nullptr;
	Derived d;

	// Неявное преобразование типа
	b = &d;
	std::cout << "Implicit convertion from Derived to Base: " << *b << '\n';

	// явное
	b = static_cast<Base*>(&d);
	std::cout << "Explicit convertion from Derived to Base: " << *b << '\n' <<
	"From Base to Derived: " << *static_cast<Derived*>(b) << '\n';

	// Ошибка компиляции: Base и NoOnesRelative - не родственники
	// b = static_cast<NoOnesRelative*>(&d);
};

bool dynamicCast(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong argument count\n";
		return false;
	}

	Base* b = new Base();
	const std::string arg = std::string(argv[1]);

	if(arg == "Base")
	{
		std::cout << *b << "\n";
	}
	else if(arg == "Derived")
	{
		std::cout << dynamic_cast<Derived*>(b);
		std::cout << *b << "\n";
	}
	else
	{
		// dynamic_cast работает в рантайме (поэтому он dynamic)
		// Если преобразование типа невозможно, он возвращает nullptr
		// (есть также перегрузка, генерирующая исключение)
		// Целевой тип должен быть полиморфным
		NoOnesRelative* noOne = dynamic_cast<NoOnesRelative*>(b);

		// Всегда нужно проверять результат dynamic_cast (иначе зачем?)
		if(noOne == nullptr)
		{
			std::cout << "Do not know how to process the argument: " << arg << '\n';
			delete b;
			return false;
		}
	}


	delete b;
	return true;
}

void constCast()
{
	std::cout << "Const cast example\n";
	
	const std::string* teacher = new std::string("Anna");
	std::cout << "Teacher name was once a constant: " << *teacher << '\n';

	*const_cast<std::string*>(teacher) = "Nicolai";
	std::cout << "But after const cast it is: " << *teacher << '\n';

	delete teacher;
}

int main(int argc, char** argv)
{
	// Немного базовых примеров
	easyStaticCast();
	std::getchar();

	// Здесь показывается, почему C-style каст может быть опасным
	// evilCStyleCast();

	// static_cast можно также использовать 
	// для преобразования типов при наследовании
	staticCastInheritance();
	std::getchar();

	// static_cast называется так, потому что действует во время компиляции
	// Однако, полиморфизм может использоваться и во время выполнения
	dynamicCast(argc, argv);
	std::getchar();

	// Константность является частью типа. 
	// Соответственно, убрать или добавить константность - преобразование типа
	// Однако потребность в const_cast скорее всего говорит 
	// о проблемах, которые нужно решать другим путём 
	constCast();
}
