#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <functional> // это для std::bind и std::function 
					  // Для использования лямбда-выражений ничего инклудить не нужно - 
					  // это встроенная функциональность C++	

#include "../vector_out.hpp"
#include "student.hpp"
#include "abc.hpp"


void lambdaVsBind(const std::vector<int>& vec)
{
	// Прибавить ко всем элементам 10 и умножить результат на 2:
	std::cout << "Lambdas vs binders!\nInitial vector:\n" << vec << 
		"\nAdd 10 and multiply by 2" <<	std::endl;

	// 1) С помощью bind
	auto plus10times2Bind = std::bind(std::multiplies<int>(),
									std::bind(std::plus<int>(),
										std::placeholders::_1, 10),
								  2);

	// 2) С помощью лямбда-выражения
	auto plus10times2Lambda = [] (int i) noexcept {return (i + 10) * 2;};
	// Лямбда выглядит куда дружелюбнее

	const auto vecSize = vec.size(); 
	std::vector<int> tmp;
	tmp.resize(vecSize);

	std::transform(vec.begin(), vec.end(), tmp.begin(), plus10times2Lambda);
	std::cout << "std::transform with lambda:\n" << tmp << std::endl;
	
	tmp.clear();
	tmp.resize(vecSize);
	std::transform(vec.begin(), vec.end(), tmp.begin(), plus10times2Bind);
	std::cout << "std::transform with binders:\n" << tmp << std::endl;
}

void lambdaVsCustomFunctor(const std::vector<int>& vec)
{
	// Пример с получением среднего значения, рализованный с использованием лямбды
	std::cout << "Lambdas vs custom functors!\nInitial vector:\n" << vec << 
		"\nCompute average" << std::endl;

	// В варианте с лямбдой меньше текста, но читается хуже
	// [&sum] - захват переменной sum по ссылке
	// Благодаря ему тело лямбды "видит" переменную sum 
	// (было бы достаточно [sum] - захват переменной по значению) 
	// и производимые им изменения sum сохраняются 
	// (а вот здесь уже нужно [&sum] - завхват переменной по ссылке)

	// Вообще на уровне компилятора разница не так велика - для каждого 
	// лямбда-выражения компилятор генерирует функциональный объект (функтор) - 
	// объект с оператором вызова operator() const. 
	// Этот объект называется замыкание (closure).
	// Захваченные переменные становятся его членами данных
	long sum = 0;
	std::for_each(vec.begin(), vec.end(), // range
					[&sum] (int elem) {sum += elem;});


	double mv = static_cast<double>(sum) / static_cast<double>(vec.size());
	std::cout << "Mean value: " << mv << std::endl;
}

void lambdaType()
{
	int x = 0;
	int y = 0;
	std::cout << "Lambda with two captures by reference!\nx = " << x << 
		"; y = " << y << std::endl;

	auto foo = [&x, &y](){ ++x; ++y; };
	// Пытаемся создать объект того же типа, что и foo
	// Не компилируется - конструктор замыкания удалён (=delete)
	// decltype(foo) fooCopy;
	foo();
	std::cout << "x = " << x << "; y = " << y << std::endl;
}

void lambdaMutable()
{
	int x = 0;
	int y = 0; 
	std::cout << "Lambda with mutable and captures by value\nx = " << x << 
		"; y = " << y << std::endl;
	
	// Без mutable нельзя
	// error: increment of read-only variable 'x'
    // auto foo = [x, y](){ ++x; ++y; };
	// Дело в том, что оператор вызова у функционального объекта-замыкания
	// по умолчанию является константным - operator() const,
	// а захваченные переменные становятся членами данных этого объекта-замыкания

	auto foo = [x, y]() mutable { ++x; ++y; };	
	foo();

	// C mutable изменения допускаются, 
	// но не сохраняются по выходу из области видимости тела лямбда-выражения - 
	// это же копия
	std::cout << "x = " << x << "; y = " << y << std::endl;
}

void lambdaReturnType()
{
	std::cout << "Testing lambda return type" << std::endl;
	// Обычно указывать тип возвращаемого значения не нужно -
	// компилятор выведет его так же, как выводит типы в шаблонах
	// и при использовании auto. Но точно так же, как и в этих случаях,
	// у него не всегда это получается без подсказки
	// Не компилируется:
	// error: inconsistent types ‘B*’ and ‘C*’ deduced for lambda return type
	// Несмотря на то, что типы В и С могут быть преобразованы один в другой, 
	// т.к. имеют общий базовый класс A, компилятор не может выполнить это 
	// преобразование автоматически

	// auto myLambda = [](int type)
	// { 
	// 	if (type == 0)
	// 	{ 
	// 		return new B();
	// 	}
	// 	else
	// 	{
	// 		return new C();
	// 	} 
	// };
	
	// Тернарный условный оператор здесь использовать нельзя
	// error: conditional expression between distinct pointer types ‘B*’ and ‘C*’ lacks a cast
	// Не может вывести возвращаемый тип функции
	// auto myLambdaBad = [](int type){return type == 0 ? new B() : new C(); };

	// Придётся ему подсказать
	auto myLambda = [](int type) -> A*
	{ 
		if (type == 0)
		{ 
			return new B();
		}
		else
		{
			return new C();
		} 
	};

	auto obj = myLambda(0);\
	std::cout << *obj << std::endl;
	delete obj;
}

int global = 10;

void lambdaCaptureNonAutomatic()
{
	std::cout << "Lets access global variable from lambda!\n" <<
		"The global value is " << global << std::endl;

	// Неавтоматические перменные не захватываются ни по значению, ни по ссылке
	// однако, глобальные переменные и так доступны внутри лямбда-выражений 
    auto captureAllVal = [=] () mutable { ++global; };
    captureAllVal();    
    std::cout << "Captured with [=]. The global value is " << global << std::endl;
    std::getchar();
    
    auto noCapture = []{ ++global; };
    noCapture();
    std::cout << "Notihng captured. The global value is " << global << 
    	"\nNothing was captured, but the global is accessible!\n"\
    	"In fact,  nothing was captured in the above example - "\
    	"only automatic variables are captured " << std::endl;
    std::getchar();

    // Здесь будет ворнинг
    // lambdas.cpp: In function ‘void lambdaCapture()’:
	// lambdas.cpp:210:28: warning: capture of variable ‘global’ with non-automatic storage duration
 	// 210 |     auto globalCaptured = [global] { ++global; };
 	//     |                            ^~~~~~
    auto globalCaptured = [global]{ ++global; };
    globalCaptured();
    std::cout << "Captured global only with [global]. The global value is " << 
    	global << std::endl;
    std::getchar();

    // Аналогично для статических переменных - они тоже неавтоматические
    static int staticInt = 20;
    std::cout << "Lets try with static variables. The static value is " << 
    	staticInt << std::endl;

    auto captureAllStatic = [=]() mutable { ++staticInt; };
    captureAllStatic();
    std::cout << "Captured with [=]. The static value is " << staticInt << std::endl;
    std::getchar();

    auto noCaptureStatic = []{ ++staticInt; };
    noCaptureStatic();
    std::cout << "Notihng captured. The static value is " << staticInt << std::endl;
    std::getchar();

    // Тоже ворнинг
    // warning: capture of variable ‘staticInt’ with non-automatic storage duration
    // 238 |     auto staticCaptured = [staticInt]{ ++staticInt; };
    auto staticCaptured = [staticInt]{ ++staticInt; };
    staticCaptured();
    std::cout << "Captured static only with [static]. The static value is " << 
    	staticInt << std::endl;
}

void lambdaCaptureThis()
{
	std::cout << "Test [*this] capture" << std::endl;
	A("dummy").getLambda()();
}

void lambdaToFunctionPointer()
{
	std::cout << "Lets try to convert lambda to function pointer!" << std::endl;
	// Лямбда-выражение ожет быть преобразовано в указатель на функцию,
	// но только если ничего не захватывается

	auto lambda = [](int i) {return (i < 10) && (i > 3); };
	bool(*fPtr)(int) = lambda;

	const int val = 7;
	std::cout << "Is " << val << " between 10 and 3?" << std::boolalpha << 
		fPtr(val) << std::endl;

	auto captLambda = [val](int i) {return (val > i); };
	// Не компилируется
	bool(*fPtr2)(int) = captLambda;
	// lambdas.cpp:233:27: error: cannot convert ‘lambdaToFunctionPointer()::<lambda(int)>’
	// to ‘bool (*)(int)’ in initialization
	//    233 |  bool(*fPtr2)(int) = captLambda;
}

// Один из способов передать лямбда-выражение в функцию - через шаблон
template <class U, class T>
void lambdaSort(std::vector<U>& vec, T func)
{
	std::cout << "Usorted: " << vec << std::endl;
	std::sort(vec.begin(), vec.end(), func);
	std::cout << "Sorted: " << vec << std::endl; 
}

void testLambdaSort(std::vector<int>& vec, std::vector<Student>& students)
{
	std::cout << "Sort increasing" << std::endl;
	lambdaSort(vec, [](int first, int second){return first < second;});
	std::getchar();

	std::cout << "Sort decreasing" << std::endl;
	lambdaSort(vec, [](int first, int second){return first > second;});
	std::getchar();

	std::cout << "Sort students" << std::endl;
	lambdaSort(students, [](const Student& first, const Student& second)
						 {return first.getAverageMark() > second.getAverageMark();});
}

int main()
{
	std::vector<int> vec{7, 5, 3, 8, 2, 6, 1, 4};
	lambdaVsBind(vec);
	std::getchar();

	lambdaVsCustomFunctor(vec);
	std::getchar();

	lambdaType();
	std::getchar();

	lambdaMutable();
	std::getchar();

	lambdaReturnType();
	std::getchar();

	lambdaCaptureNonAutomatic();
	std::getchar();

	lambdaCaptureThis();
	std::getchar();

	lambdaToFunctionPointer();
	std::getchar();

	const auto wasia = Student("Wasia", "Kotik", 3.98);
	wasia.say();
	std::getchar();

	std::vector<Student> students{wasia,
								  Student("Masha", "Umniasha", 4.11),
								  Student("Igor", "Krasavchik", 4.01) };
	testLambdaSort(vec, students);
}