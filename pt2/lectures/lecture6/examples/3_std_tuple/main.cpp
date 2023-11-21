#include <tuple>
#include <iostream>
#include <string>
#include <typeinfo>


template <typename T> 
void printHelper() 
{ 
	std::cout << "unknown type\n"; 
}

template <>
void printHelper<int>()
{
	std::cout << "int\n";
}

template <>
void printHelper<float>()
{
	std::cout << "float\n";
}

template <> 
void printHelper<bool>() 
{
	std::cout << "bool\n";
}

template <> 
void printHelper<char>() 
{
	std::cout << "char\n";
}

template <> 
void printHelper<std::string>() 
{
	std::cout << "std::string\n";
}

template <> 
void printHelper<const char*>() 
{
	std::cout << "const char*\n";
}

//cppreference on std::tuple_element_t
template<std::size_t I, class T>
void printTypeAtIndex()
{
    std::cout << "index " << I << " has type: ";
    // доступ к типу элеметна (во время компиляции)
    using SelectedType = std::tuple_element_t<I, T>;
    printHelper<SelectedType>();
}

// N Josuttis. The C++ Standard Library: A Tutorial and Reference 2012
void testTie()
{
	std::cout << "Testing std::tie" << std::endl;
	std::tuple <int, float, std::string> t(77, 1.1, "more light");
	int i;
	float f;
	std::string s;

	// std::tie(i, f, s) возвращает std::tuple<&i, &f, &s> - 
	// кортеж ссылок на i, f и s
	// присваивание распаковывает кортеж t в эти значения
	// и, таким образом, присваивает значения i, f и s через ссылки на них 
	std::tie(i, f, s) = t; // assigns values of t to i, f, and s
	std::cout << "i = " << i << "; f = " << f << "; s = " << s << std::endl;
}


int main()
{
	std::cout << "Testing std::tuple" << std::endl;
	std::tuple<int, float, std::string> t1(41, 6.3, "nico");
	
	std::cout << "Getting tuple elements with std::get<I>(tuple_item)" << std::endl;
	std::cout << std::get<0>(t1) << " ";
	std::cout << std::get<1>(t1) << " ";
	std::cout << std::get<2>(t1) << " ";
	std::getchar();

	std::cout << "Size of tuple t1 is " << std::tuple_size<decltype(t1)>() << std::endl;

	std::cout << "Create tuple with std::make_tuple and get element "\ 
		"types with std::tuple_element" << std::endl;
	auto t2 = std::make_tuple(22, 44, "anna");
	using t2Type = decltype(t2);
	printTypeAtIndex<0, t2Type>();
	printTypeAtIndex<1, t2Type>();
	printTypeAtIndex<2, t2Type>();
	std::getchar();

	testTie();
}