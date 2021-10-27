#include <queue>
#include <vector>
#include <functional>
#include <iostream>

template<class T, class Cont, class Comp>
void printQueue(std::priority_queue<T, Cont, Comp> q)
{
	while(!q.empty())
	{
		std::cout << q.top() << std::endl;
		q.pop();	
	}
}

int main()
{
	const auto data = {7, 29, 14, 30, 18, 42, 18, 11};
	
	std::cout << "priority_queue implementing maximum heap" << std::endl;
	std::priority_queue<int> priorQue;

	for (auto i: data)
	{
		priorQue.push(i);
	}

	printQueue(priorQue);
	std::getchar();
	
	std::cout << "priority_queue implementing minimum heap" << std::endl;
	std::priority_queue<int, std::vector<int>,  std::greater<int>> minHeap;

	for (auto i: data)
	{
		minHeap.push(i);
	}

	printQueue(minHeap);
}