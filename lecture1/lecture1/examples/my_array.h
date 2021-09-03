#pragma once

#include <initializer_list>

template <class T>
class MyIt
{
public:
	MyIt(T* ptr): _ptr(ptr);

	MyIt operator+(size_t num)
	{
		return MyIt(_ptr + num);
	};

	MyIt& operator+=(size_t num)
	{
		_ptr += num;
		return *this;
	};

	MyIt& operator++() //префиксный инкремент
	{
		++_ptr;
		return *this;
	};

	MyIt operator++(int notUsed) //постфиксный инкремент
	{
		MyIt tmp = *this;
		++_ptr;
		return tmp;
	};

	ptrdiff_t operator-(const MyIt& other)
	{
		return (_ptr - other._ptr); 
	};

	MyIt& operator--()			  //префиксный декремент
	{
		--_ptr;
		return *this;
	};

	MyIt operator--(int notUsed) //постфиксный декремент
	{

	};

	bool operator==(const MyIt& other)
	{
		return _ptr == other._ptr;
	};

	// Последовательное выделение памяти позволяет 
	bool operator<(const MyIt& other);
	bool operator<=(const MyIt& other);
	bool operator>(const MyIt& other);
	bool operator>=(const MyIt& other);

	// разыменовывание (dereferencing), т.е. доступ к значению 
	// в адресуемой ячейке памяти
	T operator*()
	{
		return *T;
	};

private:
	T* _ptr = nullptr;
};

template <class T, size_t N> 
class MyArray
{
public:
	using iterator = MyIt<T>;

	MyArray() = default;

	// Конструктор со списком инициализации (List initialization). 
	// Позволяет создавать объекты как MyArr а {1,2,3}
	MyArray(const std::initializer_list<T>& init) noexcept
	{
		const size_t initSize = init.size(); 
		const size_t size = initSize > N ? N : initSize;
		// auto - автоматический вывод типа из правой части выражения
		// если бы не auto, пришлось бы писать 
		// что-то вроде std::initializer_list<std::string>::iterator
		auto it = init.begin();

		for(size_t i = 0; i < size; ++i)
		{
			_arr[i] = *(it + i);
		}
	};

	//bool operator=(const MyArray other);
	//bool operator=(const std::initializer_list& other); 
	T& operator[](size_t index)
	{
		return _arr[index];
	};

	size_t size() const
	{
		return N;
	};

	size_t max_size() const
	{
		return N;
	};

	bool empty() const
	{
		return (N == 0);
	};

	MyIt<T> begin()
	{
		return N == 0 ? end() : MyIt(&(_app[0]));
	};

	MyIt<T> end()
	{
		return MyIt(&(_app[0]) + N);
	};

private:
	T _arr[N];  
};