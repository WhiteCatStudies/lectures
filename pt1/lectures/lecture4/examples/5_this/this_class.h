#pragma once

class ThisClass
{
public:
	int getVal();
	void setVal(int val);

	// не скомпилируется (см. реализацию)
	//static void printVal();

private:
	int _val;
};
