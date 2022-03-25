#pragma once
#include "fridge.h"


class Home
{
public:
	Home(size_t fridgeSize);
	// функция fridgeRaider не является членом класса Home 
	// (и какого-либо другого класса),
	// но она имеет доступ к закрытым членам класса Home.
	// передача параметра происходит по ссылке, потому что ущерб,
	// причинённый расхитителем холодильников, сохраняется
	// после завершения функции
	friend void raid(Home& home);


private:
	Fridge _fridge;
};