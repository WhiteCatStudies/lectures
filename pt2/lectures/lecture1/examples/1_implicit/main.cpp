#include <iostream>
#include <iomanip>

template <class T>
void printType(T val)
{
	std::cout << val << " has type " << typeid(val).name() << '\n';
}

void printDouble(double val)
{
	printType(val);
}

void printVeryLong(long long val)
{
	printType(val);
}

void testPromotions()
{
	// Неявное преобразование типа при передаче параметра в функцию
	// Integral promotion: 
	// целочисленный тип "расширяется" до типа большего размера,
	// меняется тип, но не значение
	std::cout << "Integral promotion:\nPass int(3), char(5) to function taking long long\n";
	int intVal = 3;
	char charVal = 5;

	printVeryLong(intVal);
	printVeryLong(charVal);

	// Floating point promotion: то же для типа с плавающей точкой
	std::cout << "Floating point promotion:\nPass float(4) to function taking double\n";
	float floatVal = 4.0f;
	printDouble(floatVal);

	// Неявное преобразование типа при присваивании
	std::cout << "Integral promotion:\nAssign char(5) to int\n"; 
	int assignedInt = charVal;
	printType(assignedInt);
}

void testConvertions()
{
	// Narrowing conversion. Может компилироваться с warning'ом
	// в зависимости от настроек компиляции

	// 2^32 + 0x00000000a - точно не помещается в unsigned int
	unsigned long long veryBig = 0xffffffffa;

	unsigned int notBigEnough = veryBig;
	std::cout << "Very big unsigned long long to unsigned int\n" <<
		"Expected: " << veryBig << "\nResult: " << notBigEnough << '\n';
	std::getchar();

	// Floating point -> integer
	float floatVal = 3.5f; 
	int intVal = floatVal;
	std::cout << "Floating point to integer\n" <<
		"Expected: " << floatVal << "\nResult: " << intVal << '\n';

	// Integer -> floating point
	intVal = 18642731;
	floatVal = intVal;
	std::cout << "Integer to floating point\n" <<  
		std::setprecision(5) << std::fixed << 
		"Expected: " << intVal << "\nResult: " << floatVal << '\n';
}

int main()
{
	// Неявные преобразования типа (Implicit conversions)
	// Promotion - тип "расширяется", но значение не меняется
	testPromotions();
	std::getchar();

	// Convertion - в результате преобразования типа значение меняется 
	testConvertions();
}
