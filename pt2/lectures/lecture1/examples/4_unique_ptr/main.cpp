#include <iostream>
#include <memory>

#include "cat.hpp"
#include "unique_ptr.hpp"


int main()
{
	{
		std::cout << "Unique Pointer should automaticaly call "\
			"the objects' destructor\n";

		const auto ptr = std::make_unique<Cat>("Wasia", "noname", 10, 2, 4);
		const auto myPtr = makeUnique<Cat>("Wasia", "noname", 10, 2, 4);
	}

	std::getchar();
	auto ptr = std::make_unique<Cat>("Wasia", "noname", 10, 2, 4);
	auto myPtr = std::make_unique<Cat>("Masia", "noname", 10, 2, 4);

	// Не компилируется - копирующие операции удалены 
	// ptr = myPtr;
	// Только перемещение
	ptr = std::move(myPtr); 
	// Деструктор вызовется только дважды - 
	// ptr = std::move(myPtr) не создаёт новый объект
}
