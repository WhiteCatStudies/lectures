#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>


template <class T>
void print(const T& cont, const std::string& name="")
{
	if (!name.empty())
	{
		std::cout << name << ": ";
	}

	for (const auto& elem: cont)
	{
		std::cout << elem << " ";
	}

	std::cout << std::endl;
}

void testBackInserter()
{
	std::cout << "Testing back inserter" << std::endl; 
	std::vector<int> coll;
	
	// Первый способ
	std::cout << "Insert elements to vector using back inserter" << std::endl;
	std::back_insert_iterator<std::vector<int>> iter(coll);
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;

	print(coll);
	std::getchar();

	// Второй способ
	std::back_inserter(coll) = 44;
	std::back_inserter(coll) = 55;
	print(coll);
	std::getchar();

	// Использование с алгоритмами: повторная вставка всех элементов 
	// в конец контейнера 
	coll.reserve(2*coll.size());

	// Первые два параметра - итераторы на начало и конец области, 
	// которую нужно скопировать из исходного контейнера
	// Третий параметр - итератор на элемент контейнера, начиная с которого 
	// будут вставлены скопированные элементы 
	std::cout << "Copy elements from the vector to the end of the same vector" << 
		std::endl;
	std::copy(coll.begin(), coll.end(), std::back_inserter(coll)); 
	print(coll);
}

void testFrontInserter()
{
	std::cout << "Testing front inserter" << std::endl;
	// У вектора нет push_front, поэтому для примера возьмём список 
	std::list<int> coll;

	// Первый способ
	std::cout << "Insert elements to list using front inserter" << std::endl;
	std::front_insert_iterator<std::list<int>> iter(coll);
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;
	print(coll);
	std::getchar();

	// Второй способ
	std::front_inserter(coll) = 44;
	std::front_inserter(coll) = 55;
	print(coll);;
	std::getchar();
	
	std::cout << "Copy elements from the list to the beginnig of the same list" <<
		std::endl;
	std::copy(coll.begin(), coll.end(), std::front_inserter(coll)); 
	print(coll);;
}

void testInserter()
{
	std::cout << "Testing general inserter" << std::endl;
	std::set<int> coll;

	// Для ассоциативных и неупорядоченных контейнеров второй параметр 
	// не играет роли - итоговая позиция элемента в контейнере будет зависеть
	// от его значения 
	std::cout << "Isert elements to set using inserter" << std::endl;
	std::insert_iterator<std::set<int>> iter(coll, coll.begin());
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;
	print(coll, "set");
	std::getchar();

	std::inserter(coll, coll.end()) = 44;
	std::inserter(coll, coll.end()) = 55;
	print(coll, "set");
	std::getchar();
	
	std::cout << "Now copy elements from set to list" << std::endl;
	std::list<int> coll2;
	std::copy(coll.begin(), coll.end(), inserter(coll2, coll2.begin()));
	print(coll, "list");
	std::getchar();
	
	// Скопируем все элементы списка в тот же список, начиная со второй позиции
	std::cout << "And then copy all the elements to the same list " \
		"starting from the second position" << std::endl;
	std::copy(coll.begin(), coll.end(), inserter(coll2, ++coll2.begin())); 
	print(coll2, "list");
}

int main()
{
	testBackInserter();
	std::getchar();	

	testFrontInserter();
	std::getchar();

	testInserter();
}