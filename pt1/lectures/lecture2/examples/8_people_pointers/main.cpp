#include <iostream>

#include "adult.h"

int main() {
    std::cout << "----------" << std::endl;
    std::cout << "Constructing Adult" << std::endl;
    Adult adult = Adult("Anya", "MIREA");
    std::cout << "----------" << std::endl;
    std::getchar();

    std::cout << "----------" << std::endl;
    std::cout << "Constructing Person" << std::endl;
    Person person = Person("Angelina", 50, 50, 80);
    std::cout << "----------" << std::endl;
    std::getchar();

    std::cout << "----------" << std::endl;
    std::cout << "The pointer points to base class object" << std::endl;
    Person* basePointer = &person;
    basePointer->say();
    // не скомпилируется - у класса Person нет такого метода
    //basePointer->goWork(); 
    // но мы можем привести тип basePointer 
    // к указателю на производный тип
    std::cout << "----------" << std::endl;
    std::getchar();

    std::cout << "----------" << std::endl;
    std::cout << "Cast pointer to Person (base) to pointer to Adult (derived)" << std::endl;
    // Здесь стоит использовать dynamic_cast, но об этом позже
    (static_cast<Adult*>(basePointer))->goWork();

    std::cout << "----------" << std::endl;
    std::getchar();

    // указатель на базовый тип может использоваться 
    // для доступа к производному типу
    // но он имеет доступ только к тому, что есть в самом базовом классе
    std::cout << "----------" << std::endl;
    std::cout << "The pointer points to derived class object" << std::endl;
    basePointer = &adult;
    basePointer->say();

    // Но если свойства производного класса унаследованы от базового класса,
    // они также доступны и имеют значения, установленные производным классом  
    basePointer->sayEnergy();
    basePointer->sayTime();
    basePointer->sayMoney();
    std::cout << "----------" << std::endl;
    std::getchar();
}
