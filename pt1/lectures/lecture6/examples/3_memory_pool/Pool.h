#pragma once

#include <new>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>


class Pool
{
public:
	Pool() = default;

	Pool(size_t size):
		_pool(size, nullptr)
	{
	}

	void* alloc(size_t size)
	{
		const auto it = std::find_if(_pool.begin(), _pool.end(),
			[](const void* item){return item == nullptr;});

		if(it == _pool.end())
		{
			_pool.push_back(nullptr);
			return &(_pool.back());
		}

		*it = malloc(size);
		return &(*it);
	}

	void dealloc(void* p)
	{
		std::cout << "Calling Pool::dealloc(void *p) for p=" << p << "\n";

		const auto it = std::find_if(_pool.begin(), _pool.end(),
			[p](const void* item){return item == p;});

		if(it != _pool.end())
		{
			*it = nullptr;
			free(p);
		}
	}

private:
	// Пул памяти хранит адреса в последовательном непрерывном участке памяти
	// Конечно, можно было бы хранить сами объекты в векторе
	// В рамках примера можно представить, 
	// что эта область памяти обладает особыми свойствами - 
	// допустим, это разделяемая память, доступная из множества процессов
	std::vector<void*> _pool;
};

// Установление соответствия между адресом памяти 
// и пулом, к которому он принадлежит - пулов может быть больше одного
// Используется для работы с пулом памяти в операторе со "стандартной" сигнатурой
// void operator delete(void* p)
std::map<void*, Pool> poolMap;

// Перегружаем стандартный оператор new с использованием malloc,
// чтобы потом с чистой совестью в операторе delete использовать free
void* operator new(size_t size)
{
	return malloc(size);
}

// operator new всегда должен возвращать void* 
// и принимать size_t первым параметром
void* operator new(size_t size, Pool& pool)
{
	std::cout << "Calling void* operator new(size_t size, Pool& pool)\n";
	void* ptr = pool.alloc(size);
	poolMap[ptr] = pool; 
	return ptr;
};

// специальный оператор delete для освобождения памяти, необходимый,
// если конструктор, вызванный инструкцией placement-new,
// сгенерировал исключение
void operator delete(void* p, Pool& pool)
{
	std::cout << "Calling void operator delete(void* p, Pool& pool)\n";
	pool.dealloc(p);
	if(poolMap.find(p) != poolMap.end())
	{
		poolMap.erase(p);		
	}
}

// Глобальный operator delete, различным образом реализующий освобождение памяти
// для адресов из пула памяти и прочих
void operator delete(void* p)
{
 	if(poolMap.find(p) != poolMap.end())
	{
		std::cout << "Calling void operator delete(void* p) for memory pool\n";
		poolMap[p].dealloc(p);
		poolMap.erase(p);
		return;
	}

	free(p);
};
