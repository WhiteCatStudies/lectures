#pragma once

class A
{
public:
	A(int i);
	~A();

protected:
	int _i;
};

class B : public A
{
public:
	B(int i, int j);
	~B();

protected:
	int _j;
};

class C : public A
{
public:
	C(int i, int k);
	~C();

protected:
	int _k;
};

class D : public C, public B
{
public:
	D(int i, int j, int k);
	~D();
	int getSum();
};

//class A 
//{};
//
//class B : public A
//{};
//
//class C : public A
//{};
//
//class D : public B, public C
//{};

