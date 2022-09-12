#include <list>
#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>


void printWithAddress(const std::list<std::string>& lst)
{
	for(auto it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << "Element: " << *it << "; Address: " << &(*it) << '\n';
	}
}

void testAccess(const std::list<std::string>& goodThings)
{
	std::cout << "-----Testing element access-----\n";

	std::cout << "Get the first and the last good things\n";
	std::cout << "The first good thing is " << goodThings.front() << 
		"\nThe last good thing is " << goodThings.back() << std::endl;

	std::getchar(); 
	// Оператора индексирования у списка нет. Доступ только через итераторы
	auto it = goodThings.begin();
	std::cout << "You should get iterators to acces other elements" << 
		"\nWhat is the second best thing?\n" << *(++it) <<
		"\nWhat is the third best thing?\n" << *(++it) <<
		"\nWait, what was the second one?\n" << *(--it) << std::endl;


	std::cout << "Are there any good things? " << std::boolalpha << !(goodThings.empty()) <<
		"\nHow many are there good things? " << goodThings.size() << std::endl;
}

void testInsert(std::list<std::string>& goodThings)
{
	std::cout << "-----Testing insert-----\n";
	
	// В отличие от вектора, у списка есть методы для вставки/удаления элемента 
	// в начало списка. Реализация STL пособствует выбору правильного контейнера:
	// хотите добавлять элементы в начало - не берите вектор - это дорого
	goodThings.push_front("Coffee");
	const auto begIt = goodThings.begin();
	std::cout << "Before insertions\n";
	printWithAddress(goodThings);

	auto it = std::find(begIt, goodThings.end(), "Cats");
	if (it != goodThings.end())
	{
		it = goodThings.insert(it, "Books");
		it = goodThings.insert(it, "Movies");
		it = goodThings.insert(it, "Music");
		it = goodThings.insert(it, "Chokolate");
		it = goodThings.insert(it, "Bycicle");
		it = goodThings.insert(it, "Sleeping");
	}

	// Видим, что адреса не последовательные, и что программирование, друзья и готовка
	// остались по прежним адресам. Операции вставки 
	// не инвалидируют никакие итераторы в списке
	std::cout << "\nAfter insertions\n";
	printWithAddress(goodThings);
}

void testErase(std::list<std::string>& goodThings)
{
	std::cout << "-----Testing erase-----\n";
	std::cout << "Good things are often bad for health. We have to refuse chokolate\n";
	auto chokoIt = std::find(goodThings.begin(), goodThings.end(), "Chokolate");
	// Возвращает итератор на следующий элемент
	auto res = goodThings.erase(chokoIt);
	std::cout << "Erase returnerd iterator to " << *res << '\n';
	// Шоколада больше нет (=
	printWithAddress(goodThings);
	
	// По идее (и по документации на cppreference) должен быть segmentation fault,
	// но g++ v. 8.1.0 и v.8.3.0 по-видимому где-то сохраняет состояние итератора
	// На MSVC в дебаге ошибка, в релизе норм.
	// Но лучше считать, что итератор на удалённый элемент списка инвалидируется - 
	// Это соответствует здравому смыслу и избавляет от сюрпризов
	std::cout << "Lets dereference chokolate iterator!\n" << *chokoIt << 
		"Proneslo?\n" << 
		"Lets try longer strings. Large memory chancks are more likely to be ovewritten\n";

	// Пример, который, скорее всего, покажет, чем плох инвалидировавшийся итератор
	std::list<std::string>::iterator it;
    {
        const std::string galliaEst = "Gallia est omnis divisa in partes tres,"\ 
        							  "quarum unam incolunt Belgae, aliam Aquitani,"\ 
        							  "tertiam qui ipsorum lingua Celtae, nostra Galli appellantur." \
        							  "Hi omnes lingua, institutis, legibus inter se differunt."\
        							  "Gallos ab Aquitanis Garumna flumen, a Belgis Matrona et Sequana dividit";
        
        std::list<std::string> gallia = {"Rhodano, continetur Garumna flumine, Oceano, finibus Belgarum",
                                         galliaEst,
                                         "Ad eas res conficiendas Orgetorix deligitur. "\
                                         "Is sibi legationem ad civitates suscipit."};
        
        it = std::find(gallia.begin(), gallia.end(), galliaEst);
        gallia.erase(it);
        // После erase
        std::cout << "Dereference\n" << *(it) << std::endl;
    }

    {
        // Просто запишем в память что-то относительно большое
        std::list<std::string> gallia = {"His rebus fiebat ut et minus late vagarentur et minus facile finitimis bellum",
                                         "Gallos ab Aquitanis Garumna flumen, a Belgis Matrona et Sequana dividit",
                                         "Ea res est Helvetiis per indicium enuntiata",
                                         "Hac oratione adducti inter se fidem et ius iurandum dant"};
    }

    // g++ v. 8.1.0 и v.8.3.0: скорее всего в консоли частично строка 
    // "Gallia est omnis..." и мусор
    std::cout << "Dereference\n" << *(it);
    // Скорее всего итератор не инкрементировался и указывает всё туда же 
    std::cout << "\nIncrement\n" << *(it++) << std::endl;
    // Мораль: если исходя из логики структуры данных 
    // итератор инвалидируется в результате данной операции
    // значит, так оно и есть
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const std::list<T>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}

void testMerge()
{
	std::cout << "-----Testing merge-----\n";

	std::list<int> list1 = {5, 9, 0, 1, 3};
    std::list<int> list2 = {8, 7, 2, 6, 4};
 
	// Списки должны быть отсортированы, чтобы порядок элементов 
	// в результирующем списке имел какой-то смысл
    list1.sort();
    list2.sort();
    std::cout << "list1:  " << list1 << "\n";
    std::cout << "list2:  " << list2 << "\n";
    
	// Копирований не происходит: элементы перемещаются из списка-параметра
    list1.merge(list2);
    std::cout << "List1 after merge: " << list1 << "\n";
    std::cout << "List2 after merge: " << list2 << std::endl;
}

void testSplice()
{
	std::cout << "-----Testing splice-----\n";

    std::list<int> list1 = {1, 2, 3, 4, 5};
    std::list<int> list2 = {10, 20, 30, 40, 50};
 
    auto it = list1.begin();
    // Дважды инкрементирует итератор
    std::advance(it, 2);
 
 	// Вставляет в list1 все элементы list2 на поизцию,
 	// следующую за той, на котору указывает it
 	// list2 остаётся пустым
 	// O(1)
    list1.splice(it, list2);
    std::cout << "list1: " << list1 << "\n";
    std::cout << "list2: " << list2 << "\n";
 
 	// Вставляет в list2 элементы от it до list1.end() 
 	// на позицию, следующую за той, на которую указывает it
 	// O(std::distance(first, last))
 	std::cout << "The distance betweent first and last is " << 
 		std::distance(it, list1.end()) << std::endl;
    list2.splice(list2.begin(), list1, it, list1.end());
 
  	// Для it следующая позиция - это 3, т.к. это старый итератор
 	// Даже если итератор не инвалидирован, часто после изменения контейнера 
 	// лучше взять новый, чтобы быть уверенным в позиции
    std::cout << "list1: " << list1 << "\n" << "list2: " << list2 << std::endl;
}

int main()
{
	std::list<std::string> goodThings{"Programming", "Friends", "Cats", "Cooking"};
	testAccess(goodThings);
	std::getchar();

	testInsert(goodThings);
	std::getchar();

	testErase(goodThings);
	std::getchar();

	testMerge();
	std::getchar();

	testSplice();
}