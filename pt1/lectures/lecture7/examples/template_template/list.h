#pragma once

// Узел односвязного списка: 
// содержит данные и указатели на следующий узел
template <class U>
struct Node
{
	U data = U();
	Node* next = nullptr;

	bool hasNext() const
	{
		return next != nullptr;
	};

};

// Односвязный список
template <class T> 
class List
{
	Node<T>* _head = nullptr;

public:
	Node<T>* front() const
	{
		return _head;
	};

	void pushFront(T data)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = data;
		newNode->next = _head;
		_head = newNode;
	};

	bool empty() const
	{
		return _head == nullptr;
	};

	T popFront()
	{
		Node<T>* popped = _head;
		T data = popped->data;

		_head = _head->next;
		delete popped;
		return data;
	};

	// другие методы:
	// добавить узел после определённого узла 
	// очистить узел после определённого узла
	// ...

	~List()
	{
		Node<T>* cur = _head;
		while (cur != nullptr)
		{
			Node<T>* next = cur->next;
			delete cur;
			cur = next;
		}
	};
};

