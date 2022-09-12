#include <iostream>

template <class T>
class MyAlloc
{
public:
	// member types - члены-типы
	// Используются для доступа к формальным параметрам шаблона снаружи класса 
	// MyAlloc::size_type func() {...} 

	typedef std::size_t 	size_type;
	typedef std::ptrdiff_t  difference_type;
	typedef T* 				pointer;
	typedef const T* 		const_pointer;
	typedef T& 				reference;
	typedef const T& 		const_reference;
	typedef T 				value_type;

	// память выделяется, но не инициализируется 
	T* allocate (std::size_t num) 
	{
		// используется глобальная версия оператора new
		std::cout << "Allocating " << num << " bytes" << std::endl;
		return static_cast<T*>(::operator new(num*sizeof(T)));
	};

	void deallocate (T* p, std::size_t num) 
	{
		std::cout << "Freeing " << num << " bytes" << std::endl;
		// глобальный delete
		::operator delete(p);
	};
};