#include <iostream>

#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <set>

#include <algorithm>
#include <numeric>
#include <functional>

#include <cassert>

#include "../vector_out.hpp"


void testIsPermutation()
{
	std::vector<int> coll1{1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int> coll2{1, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::deque<int> coll3{11, 12, 13, 19, 18, 17, 16, 15, 14, 11};

	std::cout << "Test if collections are composed of equal elements "\
		"no matter what their order is with std::is_permutation\ncoll1 = " <<
		coll1 << "\ncoll2 = " << coll2 << "\ncoll3 = " << coll3 <<
		"\nCompare coll1 and coll2" <<  std::endl;  

	if (std::is_permutation(coll1.cbegin(), coll1.cend(), coll2.cbegin()))
	{
		std::cout << "coll1 and coll2 have equal elements" << std::endl;
	}
	else 
	{
		std::cout << "coll1 and coll2 don’t have equal elements" << std::endl;
	}

	std::getchar();

	std::cout << "Check if the number of even and odd elements in coll1 and coll3 " \
		"is the same with std::is_permutation" << std::endl;
	
	if(std::is_permutation(coll1.cbegin(), coll1.cend(), coll3.cbegin(), 
			[](int elem1, int elem2) {return elem1 % 2 == elem2 % 2;})) 
	{
		std::cout << "Numbers of even and odd elements match" << std::endl;
	}
	else 
	{
		std::cout << "Numbers of even and odd elements don’t match" << std::endl;
	}
}

void testLexic()
{
	// Правла таковы:
	// Две последовательности сравниваются поэлементно
	// Сравнение происходит по первым несовпадающим элементам - 
	// например, если элемент из первой последовательности больше элемента из второй,
	// первая последовательность лексигорафически больше второй последовательности
	// Если одна последовательность является частью другой, меньше та, которая короче
	// Пустая последовательность меньше непустой
	// Последовательности, имеющие равную длину, все элементы которых равны, 
	// лексикографически равны
	// Две пустые последовательности лексикографически равны
	std::list<int> c1, c2, c3, c4;
	// Списки различаются, начиная с 5-го элемента
	c1 = {1, 2, 3, 4, 5};
	c4 = c3 = c2 = c1;

	c1.push_back(7);

	c3.push_back(2);
	c3.push_back(0);
	
	c4.push_back(2);
	
	std::vector<std::list<int>> cc;
	// Каждая по два раза
	cc.insert(cc.begin(), {c1, c2, c3, c4, c3, c1, c4, c2 });
	
	std::cout << "Test std::lexicographical_compare\nInitial sequences" << std::endl;
	const auto printAll = [](const std::list<int>& l){std::cout << l << std::endl;};
	std::for_each(cc.cbegin(), cc.cend(), printAll);
	std::getchar();

	std::sort(cc.begin(), cc.end(), 
		[](const std::list<int>& first, const std::list<int>& second)
		{ return std::lexicographical_compare(first.begin(), first.end(),
											  second.begin(), second.end());});

	std::cout << "After sorting in lexicographical order" << std::endl;
	for_each (cc.cbegin(), cc.cend(), printAll);
}

void testCopyBackwards()
{
	// строка "..........abcdef.........."
	std::string source(10, '.');
	for (char c = 'a'; c <= 'f'; c++)
	{
		source.push_back(c);
	} 

	source.insert(source.end(), 10, '.');

	std::string s1(source.cbegin(), source.cend());
	// Копируем "abcdef" в ту же строку, но начиная с 7ой позиции:
	// получится ".......abcdefdef.........."
	std::copy(s1.cbegin() + 10, s1.cbegin() + 16, 
		s1.begin() + 7);

	// copy all letters three elements behind the ’f’
	std::string s2(source.cbegin(), source.cend());
	// Третий параметр copy - итератор на начало интервала, куда будем копировать
	// Третий параметр copy_backward - итератор на конец интервала, 
	// куда будем копировать. s2.begin() + 19 - это на 3 позиции дальше f
	// Копирование идёт в обратном порядке - последний элемент копируется первым, - 
	// но относительный порядок элементов сохраняется
	// Получится строка "..........abcabcdef......."
	std::copy_backward(s2.cbegin() + 10, s2.cbegin() + 16, 
		s2.begin() + 19);

	std::cout << "std::copy vs. std::copy_backward\n" << 
		source << "\n" << s1 << "\n" << s2 << std::endl;
}

void testGenerate()
{
	std::vector<int> vec(10);

	std::generate(vec.begin(), vec.end(), [i = 0]() mutable {return i++;});
	std::cout << "Test std::generate: " << vec << std::endl;
}

void testRemove()
{
	const size_t size = 12;
	assert((size >= 2) && (size % 2 == 0));

	const auto half = size / 2;
	std::list<int> lst(size);
	
	const auto decrFunc = [i = half]() mutable { return i--;};
	std::generate_n(lst.begin(), half, decrFunc);
	std::generate_n(++lst.rend(), half, decrFunc);

	const int toRemove = 3; 
	std::cout << "Test std::remove. Lets remove " << toRemove << "\npre:  " <<
		lst;
	std::getchar();

	// std::remove не удаляет элементы, а смещает остальные элементы таким образом,
	// чтобы они перезаписали те, которые нужно было удалить
	// и возвращает итератор на конец интервала, не содержащего перезаписанных элементов  
	const auto remIt = std::remove(lst.begin(), lst.end(), toRemove);
	std::cout << "post: " << lst << "\nElements removed: " << 
		std::distance(remIt, lst.end());
	std::getchar();

	// Remove-erase idiom 
	lst.erase(remIt, lst.end());
	std::cout << "Removed elements for real\n" << lst;

	// remove_copy
	std::cout << "\nNow print all elements except equal to 4";
	std::getchar();
	std::remove_copy(lst.begin(), lst.end(), 
		std::ostream_iterator<int>(std::cout, " "), 4);
	std::cout << std::endl;
}

void testStableSort()
{
	std::vector<std::string> coll1 = { "1xxx", "2x", "3x", "4x", "5xx", "6xxxx",
									   "7xx", "8xxx", "9xx", "10xxx", "11", "12",
									   "13", "14xx", "15", "16", "17" };
	std::vector<std::string> coll2(coll1);
	
	std::cout << "std::sort vs. std::stable_sort\nOn entry: " << coll1;

	// Будем сортировать по возрастанию длины строки
	const auto legngthCompare = 
		[](const std::string& first, const std::string& second)
		  { return first.length() < second.length();};

	std::sort(coll1.begin(), coll1.end(), legngthCompare);
	std::stable_sort(coll2.begin(), coll2.end(), legngthCompare);
	
	std::cout << "\nstd::sort: " << coll1 << "\nstd::stable_sort: " << coll2 << 
		std::endl;
}

void testNthElement()
{
	std::vector<int> v{5, 10, 6, 4, 3, 2, 6, 7, 9, 3};
    std::cout << "Test std::nth_element\nInitial sequence is: " << v;
    std::getchar();

    auto m = v.begin() + v.size()/2;
    // n = 5. Все элементы слева будут меньше пятого по величине элемента массива
    // справа - больше
    std::nth_element(v.begin(), m, v.end());
    std::cout << "After nth_element sort: " << v << "\nThe median is " << 
    	v[v.size()/2] << std::endl;
}

void testPartition()
{
	const size_t half = 9;
	const size_t size = 2 * half;
	std::vector<int> coll1(size);

	// Заполнили половину контейнера целыми числами от 1 до 9
	std::generate_n(coll1.begin(), half, [i = 1]() mutable { return i++; });
	const auto halfIt = coll1.begin() + half;
	// Скопировали первую половину во вторую половину
	std::copy(coll1.begin(), halfIt, halfIt);

	std::vector<int> coll2(coll1.begin(), coll1.end());

	std::cout << "std::partition vs std::stable_partition\nInitial vector is " <<
		coll1;

	// В обоих случаях в левой части интервала будут те элементы,
	// для которых предикат возвращает true 
	const auto pred = [](int elem){ return elem % 2 == 0;};
	const auto oddPos1 = std::partition(coll1.begin(), coll1.end(), pred);
	const auto oddPos2 = std::stable_partition(coll2.begin(), coll2.end(), pred);

	std::cout << "\nstd::partition: " << coll1 << 
		"First odd element: " << *oddPos1 <<  
		"\nstd::stable_partition: " << coll2 << 
		"First odd element: " << *oddPos2 << std::endl;
}

void testRotate()
{
	std::set<int> coll{1, 2, 3, 4, 5, 6, 7, 8, 9, };

	// Это будет первый элемент после сдвига
	// На освободившиеся в результате сдвига позиции запишутся элементы,
	// которые предшествовали данному элементу до сдвига  
	const auto pos = std::next(coll.cbegin(), 4);

	std::cout << "Test std::rotate_copy\nInitial sequence is " << coll << 
		"\nNew first element should be " << *pos << 
		"\nRotated sequence is: ";
	std::rotate_copy(coll.cbegin(), pos, coll.cend(), 
		std::ostream_iterator<int>(std::cout, " "));

	// Сама коллекиця не меняется. std::set - это чёрно-красное дерево,
	// в нём вообще нельзя менять порядок элементов, только за счёт 
	// вставок/удалёний 
	std::cout << "\nInitial sequence is " << coll << std::endl;
}

void testPermutation()
{
	std::vector<int> coll{1, 2 , 3};
	std::cout << "Test permutation algorithms\nInitial sequence: " << coll << 
		"\nPermutations withstd::next_permutation:\n";

	// Выполняются перестановки, пока из 1, 2, 3 не будет получено 3, 2, 1 - 
	// пока интервал не будет отсортирован в порядке убывания
	// (максимум 3! = 6 перестановок)
	while (std::next_permutation(coll.begin(), coll.end())) 
	{
		std::cout << coll << "\n"; 
	}

	std::cout << "The sequence after permutations with std::next_permutation: " << 
		coll << 
		"\nPermutations with prev_permutation:\n";

	// Выполняются перестановки, пока интервал не будет отсортирован
	// в порядке возрастания
	// Поэтому на данный момент ничего не выводится 
	while (std::prev_permutation(coll.begin(),coll.end())) 
	{
		std::cout << coll << "\n"; 
	}

	// std::prev_permutation вернула false, но перестановку выполнила
	std::cout << "The sequence after permutations with std::prev_permutation: " << 
		coll;
	
	// А вот теперь получится
	std::cout << "\nPermutations with prev_permutation:\n";
	while (std::prev_permutation(coll.begin(),coll.end())) 
	{
		std::cout << coll << "\n"; 
	}
}

void testSet()
{
	{
		const std::vector<int> v1 = {1, 2, 3, 4, 5}; 
		const std::vector<int> v2 = {      3, 4, 5, 6, 7}; 
		std::vector<int> dest1;

		std::set_union(v1.begin(), v1.end(),
					   v2.begin(), v2.end(),
					   std::back_inserter(dest1));

		std::cout << "Test set algorithms\nThe union of " << v1 << "and " << v2 <<
			"is " << dest1;
	}

	{
		const std::vector<int> v1 = {1, 2, 3, 4, 5, 5, 5}; 
		const std::vector<int> v2 = {      3, 4, 5, 6, 7}; 
		std::vector<int> dest1;

		// Если в первом интервале n равных элементов, а вто втором - m,
		// в итоговом интервале будет max(n, m) 
		std::set_union(v1.begin(), v1.end(),
					   v2.begin(), v2.end(),
					   std::back_inserter(dest1));

		std::cout << "\nTest set algorithms\nThe union of sets " << v1 << "and " << v2 <<
			"is " << dest1 << std::endl;
	}

    {
	    const std::vector<int> v1 {1, 2, 5, 5, 5, 9};
	    const std::vector<int> v2 {2, 5, 7};
	    std::vector<int> diff;
	 
	    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
	                        std::inserter(diff, diff.begin()));

	    std::cout << "\nThe difference between sets " << v1 << " and " << v2 <<
	    	" is " << diff << std::endl;
	}
}

void testNumeric()
{
	{
		std::vector<int> v{4, 6, 9, 13, 18, 19, 19, 15, 10};
		std::cout << "Test std::adjacent_difference\nBefore: " << v;
		std::adjacent_difference(v.begin(), v.end(), v.begin());
		std::cout << "After: " << v << std::endl;
	}

	std::getchar();

	{
	    std::vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // std::vector<int>v(10, 2);
	 
	    std::cout << "Test std::partial_sum\nThe first 10 even numbers are: ";
	    std::partial_sum(v.begin(), v.end(), 
	                     std::ostream_iterator<int>(std::cout, " "));
	 
	    std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
	    std::cout << "\nThe first 10 powers of 2 are: " << v << std::endl;
	}

	std::getchar();
	{
		constexpr int n = 6;
		constexpr int m = 9;

		std::cout << "Greated common divisor of " << n << " and " << m  << " is " <<
			std::gcd(n, m) << 
			"\nLeast common multiple of " << n << " and " << m  << " is " <<
			std::lcm(n, m)  << std::endl;
	}
}

int main()
{
	testIsPermutation();
	std::getchar();

	testLexic();
	std::getchar();

	testCopyBackwards();
	std::getchar();

	testGenerate();
	std::getchar();

	testRemove();
	std::getchar();

	testStableSort();
	std::getchar();

	testNthElement();
	std::getchar();

	testPartition();
	std::getchar();

	testRotate();
	std::getchar();

	testPermutation();
	std::getchar();

	testSet();
	std::getchar();

	testNumeric();

}