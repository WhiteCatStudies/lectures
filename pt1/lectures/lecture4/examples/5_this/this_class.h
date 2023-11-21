#pragma once

class ThisClass
{
public:
	int getVal();
	void setVal(int val);

	const ThisClass* getThis() const;

	// не скомпилируется (см. реализацию)
	//static void printVal();

private:
	int _val;
};
