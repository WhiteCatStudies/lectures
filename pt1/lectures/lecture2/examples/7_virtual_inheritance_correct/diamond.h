#pragma once

class A
{
public:
	A(int i);
	~A();

protected:
	int _i;
};

class B : virtual public A
{
public:
	B(int i, int j);
	~B();

protected:
	int _j;
};

class C : virtual public A
{
public:
	C(int i, int k);
	~C();

protected:
	int _k;
};

class D : public B, public C
{
public:
	D(int i, int j, int k);
	~D();
	int getSum();
};


