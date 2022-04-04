#include <iostream>
#include <iomanip>

#include "list.h"
#include "stack.h"

void testList()
{
	std::cout << "Testing list" << std::endl;
	List<int> list;
	list.pushFront(3);
	list.pushFront(2);
	list.pushFront(1);

	Node<int>* node = list.front();

	while (!list.empty())
	{
		std::cout << list.popFront() << "\n";
	}

	std::cout << "Is list empty? " << std::boolalpha << list.empty() << std::endl;
}


int main()
{
	testList();

	std::cout << "Stack test!" << std::endl;
	Stack<double> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	while (!stack.empty())
	{
		std::cout << stack.pop() << "\n";	
	}

}
