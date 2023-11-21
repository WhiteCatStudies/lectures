#include <iostream>


class Empty
{
public:
	void Foo() 
	{

	}

	void FooNotOverridden()
	{

	}
};


class Parent 
{
public:
	virtual void Foo() 
	{

	}

	virtual void FooNotOverridden()
	{

	}
};


class Derived : public Parent 
{
public:
	void Foo() override
	{

	}
};


void sayObjSize()
{
	Empty empty;
	Parent emptyVirtual;
	std::cout << "size of object of an empty class: " << sizeof(empty) << 
		"\nsize of object of an empty class with virtual metohds: " << 
		 sizeof(emptyVirtual) << std::endl;
}

int main() 
{
	// Размер объекта класса с виртуальными методами отличается от размера
	// объекта аналогичного класса без виртуальных методов на 8 бaйт - размер
	// указателя в x64 архитектуре

	// Этот указатель - vptr, указатель на таблицу виртуальных методов (vtable),
	// за счёт которой компилятор реализует позднее связывание 
	// (late binding, dynmaic dispatch и тд). Технически это и есть полиморфизм

	sayObjSize();
	std::getchar();

	// Parent p1, p2;
	// Derived d1, d2;

 	std::cout << "done\n";
}