#include <iostream>
#include <functional> // функторы STL
#include <vector>
#include <algorithm> 

#include "../vector_out.hpp"
#include "person.hpp"

using namespace std::placeholders; // _1, _2 ...


void testTransform(std::vector<int>& vec)
{
	std::cout << "Initial vector is:\n" << vec << std::endl; 

	// Изменение знака на противоположный
	std::transform (vec.cbegin(), vec.cend(), // исходный интервал
		vec.begin(), // интервал, куда будет записан результат 
		std::negate<int>()); // операция
	
	std::cout << "Vector after negation:\n" << vec << std::endl;
	std::getchar();

	// Возведение в квадрат
	std::transform(vec.cbegin(), vec.cend(), // первый множитель
		vec.cbegin(), // второй множитель
		vec.begin(), // место хранения результата
		std::multiplies<int>()); //операция

	std::cout << "Squared:\n" << vec << std::endl; 
}

void testFindIf(const std::vector<int>& vec)
{
	// плэйсхолдер _1 показывает, что первый параметр будет передан позже
	// (при вызове operator())
	// Это более современный вариант bind1st и bind2nd
	const auto found = std::find_if(vec.cbegin(), vec.cend(),
		std::bind(std::logical_and<bool>(), 
					std::bind(std::greater_equal<int>(), _1, 100),
					std::bind(std::less_equal<int>(), _1, 300)));

	if (found != vec.cend())
	{
		std::cout << "The first element in [100; 300] is " << *found << 
			std::endl;
	}
	else
	{
		std::cout << "All elements are less the 100 or greater than 300" << 
			std::endl;
	}
}

void f(int n1, int n2, int n3, const int& n4, int n5)
{
	std::cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << 
		std::endl;
}

void testBind()
{
	std::cout << "More on bindings" << std::endl;

	int n = 7;
	auto f1 = std::bind(f, _2, 42, _1, std::cref(n), n);
	// всего у f 5 параметров
	// Три из них определены заранее, два буду заданы позже
	// Первый параметр f буден передан позже при вызове f1, 
	// причём к нему будет привязан второй параметр f1
	// Второй параметр f - 42, при вызове f1 передавать его уже не надо
	// Третий параметр f будет передан позже при вызове f1
	// причём к нему будет привязан первый параметр f1
	// Четвертый параметр f - константная ссылка на n
	// Пятый параметр f - копия n

	// После "привязывания" заменяем значение n. 
	// Четвертый параметр f будет равен 10. 
	// На копию (пятый параметр) это никак не влияет 
	// "Непривязанные" параметры не используются 
	n = 10;  
	f1(1, 2, 1001, 2002);
}

void testMemberBind()
{
	std::cout << "Testing memeber functions binding" << std::endl;

	std::vector<Person> coll = {Person("Tick"), Person("Trick"), 
									Person("Track")};
	
	// Первая версия print для всех элементов (с одним параметром)
	// Этот параметр - this для каждого экземпляра класса Person
	std::cout << "Print with one parameter" << std::endl; 
	std::for_each(coll.begin(), coll.end(),
		std::bind(&Person::print, _1));
	std::getchar();

	// То же самое
	std::for_each(coll.begin(), coll.end(),
		std::mem_fn(&Person::print));
	std::getchar();

	// Вторая версия print для всех элементов (с двумя параметрами)
	std::cout << "Print with two parameters" << std::endl;
	std::for_each(coll.begin(), coll.end(),
		std::bind(&Person::print2, _1, "Person: "));
	std::getchar();

	// Можно и напрямую вызвать
	// Создали объект класса bind и вызвали его operator() с параметром
	std::cout << "Direct call of temporary function object" << std::endl;
	bind(&Person::print2, _1, "This is: ")(Person("nico"));
}

int main()
{
	std::vector<int> vec = {1, 2, 3, 5, 7, 11, 13, -17, -19};

	testTransform(vec);
	std::getchar();

	testFindIf(vec);
	std::getchar();

	testBind();
	std::getchar();

	testMemberBind();
}