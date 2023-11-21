#pragma once
#include <memory>

// Патерн Type Erasure - способ хранить объект без явного определения его тпиа
// на примере std::function

// Собственно, MyFunction
template <class UnusedT>
class MyFunction;

// Частичная специализация MyFunction, 
// где происходит всё интересное 
template <class ReturnType, class... ArgumentTypes>
class MyFunction<ReturnType (ArgumentTypes...)>
{
public:
	MyFunction() = default;

	// Нужна возможность передать объект любого типа - 
	// поэтому нужен шаблонный конструктор
	// Однако, этот объект также надо сохранить для поледующего вызова
	// при этом сам класс MyFunction ничего не знает о типе FunctionT - 
	// этот тип - формальный параметр шаблонного конструктора, а не класса MyFunction 
	// (иначе класс MyFunction не скрывал бы тип FunctionT - 
	// чтобы создать объект MyFunction нужно было бы делать MyFunction<SomeType>())
	// В классе MyFunction хранить не можем, но можем в каком-нибудь другом классе.
	// Для этого используем указатель на объект класса FunctionHolderBase

	template <class FunctionT>
	MyFunction(FunctionT f): 
		_invoker(new FunctionHolder<FunctionT>(f))
	{}

	ReturnType operator()(ArgumentTypes... args) 
	{
		return _invoker->invoke(args...);
	}

private:
	// Абстрактный базовый класс для объекта, который будет хранить наш
	// функциональный объект
	// Это не шаблонный класс - класс MyFunction может хранить указатель на объект этого класса,
	// по-прежнему ничего не зная о типе объекта, ради хранения которого используется MyFunction
	// (создать объект нельзя - класс абстрактный) 
	class FunctionHolderBase
	{
	public:
		FunctionHolderBase() = default;
		virtual ~FunctionHolderBase() = default;
		virtual ReturnType invoke(ArgumentTypes... args) = 0;
	};

	// FunctionHolder определяет поведение invoke
	// и он же хранит переданный функциональный объект, потому что это шаблонный класс
	// с формальным параметром FunctionT
	template <class FunctionT>
	class FunctionHolder : public FunctionHolderBase 
	{
	public:
		FunctionHolder(FunctionT func): 
			FunctionHolderBase(), 
			_mFunction(func) 
		{}

		~FunctionHolder() override = default;

		ReturnType invoke(ArgumentTypes... args) override final 
		{
			return _mFunction(args...);
		}

	private:
		FunctionT _mFunction;
	};

	// А класс MyFunction хранит его в типе FunctionHolderBase
	// std::unique_ptr - способ владения указателем. Его нельзя копировать,
	// можно только перемещать

	std::unique_ptr<FunctionHolderBase> _invoker;
};
