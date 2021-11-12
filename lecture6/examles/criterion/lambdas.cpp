#include <iostream>
#include <algorithm>
#include <vector>
#include <functional> // это для bind и компании. 
					  // Для использования лямбд ничего инклудить не нужно - 
					  // это встроенная функциональность C++	

#include "../vector_out.hpp"
#include "student.hpp"


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
	auto plus10times2Lambda = [] (int i) {return (i + 10) * 2;};
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

	long sum = 0;
	std::for_each (vec.begin(), vec.end(), // range
						[&sum] (int elem) {sum += elem;});
	// В варианте с лямбдой меньше текста, но читается хуже
	// [&sum] - захват переменной sum по ссылке
	// Благодаря ему тело лямбды "видит" переменную sum 
	// (было бы достаточно [sum] - захват переменной по значению) 
	// и производимые им изменения sum сохраняются 
	// (а вот здесь уже нужно [&sum] - завхват переменной по ссылке)

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

	auto foo = [x, y]() mutable { ++x; ++y; };	
	foo();

	// C mutable изменения допускаются, 
	// но не сохраняются по выходу из области видимости тела лямбда-выражения - 
	// это же копия
	std::cout << "x = " << x << "; y = " << y << std::endl;
}

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

	const auto wasia = Student("Wasia", "Kotik", 3.98);
	wasia.say();
	std::getchar();

	std::vector<Student> students{wasia,
								  Student("Masha", "Umniasha", 4.11),
								  Student("Igor", "Krasavchik", 4.01) };
	testLambdaSort(vec, students);
}