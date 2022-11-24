#include <iostream>
#include <iomanip>
#include <utility>
#include <iterator>
#include <typeinfo>
#include <unordered_set>
#include <unordered_map>
#include <string>

template <typename T1, typename T2>
std::ostream& operator << (std::ostream& strm, const std::pair<T1,T2>& p)
{
	return strm << "[" << p.first << "," << p.second << "]";
}

template <typename T>
void printHashTableState (const T& cont)
{
	std::cout << "size: " << cont.size() << "\n";
	std::cout << "buckets: " << cont.bucket_count() << "\n";
	std::cout << "load factor: " << cont.load_factor() << "\n";
	std::cout << "max load factor: " << cont.max_load_factor() << "\n";

	// Тип итератора (iterator category) покажет, какой тип списка 
	// используется в цепочках
	if (typeid(typename std::iterator_traits <typename T::iterator>::iterator_category) == 
		typeid(std::bidirectional_iterator_tag)) 
	{
		std::cout << "chaining style: doubly-linked" << std::endl;
	}
	else 
	{
		std::cout << "chaining style: singly-linked" << std::endl;
	}

	// Распределение элементов по бакетам
	std::cout << "data: " << std::endl;
	for (auto idx=0; idx != cont.bucket_count(); ++idx)
	{
		std::cout << " b[" << std::setw(2) << idx << "]: ";
		// У неупорядоченных контейнеров есть дополнительный тип итератора - 
		// local_iterator 
		// Это итераторы на списки, которые содержатся в каждом бакете (на цепочки)
		for (auto pos=cont.begin(idx); pos != cont.end(idx); ++pos) 
		{
			std::cout << *pos << " ";
		}

		std::cout << std::endl;
	}
}

void testSet()
{
	std::cout << "Testing unordered set" << std::endl;
	std::unordered_set<int> intset = {1, 2, 3, 5, 7, 11, 13, 17, 19};
	printHashTableState(intset);
	std::getchar();
	// Посмотрим, будет ли rehash
	std::cout << "Insert some other elements and see if rehash happens" << std::endl;
	intset.insert({-7, 17, 33, 4});
	printHashTableState(intset);
}

void testMap()
{
	// Англо-немецкий словарь
	std::cout << "Testing unordered multimap" << std::endl; 
	std::unordered_multimap<std::string, std::string> dict = {
		{"day", "Tag"},
		{"strange", "fremd"},
		{"car", "Auto"},
		{"smart", "elegant"},
		{"trait", "Merkmal"},
		{"strange", "seltsam"}
	};
	printHashTableState(dict);
	std::getchar();

	std::cout << "Insert some other elements and see if rehash happens" << std::endl;
	dict.insert({
		{"smart", "raffiniert"},
		{"smart", "klug"},
		{"clever", "raffiniert"}
	});
	printHashTableState(dict);
	std::getchar();
	
	std::cout << "Change maximum load factor and see if rehash happens" << std::endl;
	// max_load_factor меняет хэш-функцию и число бакетов 
	// (не вызывает rehash), но когда rehash будет вызван в
	// в результате вставки новых элементов или вручную,
	// новый max_load_factor будет учтён (g++ 8.1.0 MinGW)
	dict.max_load_factor(0.2);
	printHashTableState(dict);
	std::getchar();

	std::cout << "Insert new element and see if rehash happens for new load factor" <<
		std::endl;
	dict.insert({"Cat", "Katze"});
	printHashTableState(dict);
}

void testRehash(size_t num, float maxLoadFactor)
{
	std::cout << "Default-constructed set" << std::endl; 
	std::unordered_set<int> test;
	printHashTableState(test);
	std::getchar();

	std::cout << "Rehashed for " << num << 
		" elements with max load factor " << maxLoadFactor << std::endl;

	test.max_load_factor(maxLoadFactor);
	test.rehash(num);
	printHashTableState(test);
}

void testReserve(size_t num, float maxLoadFactor)
{
	std::cout << "Default-constructed set" << std::endl; 
	std::unordered_set<int> test;
	printHashTableState(test);
	std::getchar();

	std::cout << "Reserved for " << num << 
		" elements with max load factor " << maxLoadFactor << std::endl;

	test.max_load_factor(maxLoadFactor);
	// cppreference: 
	// void reserve( size_type count );
	// Effectively calls rehash(std::ceil(count / max_load_factor()))
	test.reserve(num);
	printHashTableState(test);
}

int main()
{
	testSet();
	std::getchar();

	testMap();
	std::getchar();

	const size_t num = 10;
	const float maxLoadFactor = 0.5;
	testRehash(num, maxLoadFactor);
	std::getchar();

	testReserve(num, maxLoadFactor);
}