#include <ranges>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

#include "person.h"


void testViews()
{
	const std::vector<Person> people{{"Anna", "Engineer", true},
	{"Wasia", "Programmer", false},  {"Oleg", "Cat", false},
	{"Masha", "Student", true}, 	 {"Victor", "Driver", false},
	{"Alice", "Hairdresser", true},  {"Elena", "Rich woman", true},
	{"Katia", "Programmer", true}};

	// Классические алгоритмы STL неудобно применять друг к другу последовательно - 
	// требуются промежуточные хранилища для результатов
	// std::ranges спешат на помощь!

	const auto isFemale = [](const Person& person){ return person.isFemale; };
	const auto getName = [](const Person& person){ return person.name; };
	const size_t count = 3;

	// std::views::filter - "пропускает" только те элементы в диапазоне,
	// для которых предикат возвращает true
	// std::views::transform - преобразует все элементы диапазона 
	// std::views::take - извлекает первые n элементов из диапазона
	// Уже лучше, но некрасиво
	std::cout << "Direct application of views\n";
	std::ranges::copy(
		std::views::take(
			std::views::transform(
				std::views::filter(people, [](const Person& person){ return person.isFemale;}),
			[](const Person& person){ return person.name;}), 
		count),
	std::ostream_iterator<std::string>(std::cout, " < "));

	std::getchar();

	// Перегруженный оператор | 
	std::cout << "Piping the views\n";
	std::ranges::copy(
			people | std::views::filter(isFemale) | std::views::transform(getName) | 
			std::views::take(count), 
		std::ostream_iterator<std::string>(std::cout, " < ")
	);
}

void testActions()
{
	std::vector<std::string> words{"You", "might", "recognize", "the", "problem", 
		"here", "If", "we", "weren’t", "using", "range", "variants", "of", "the",
		"algorithms", "the", "“bad”", "variant", "would", "crash", "at", "runtime"};

	std::vector<std::string> shortUnique = std::action::sort | 
		std::action::unique | std::views::take(5);

	std::ranges::copy(shortUnique, 
		std::ostream_iterator<std::string>(std::cout, " "));
}


int main()
{
	testViews();
	testActions();
}

