/*
Перегрузка глобальных операторов ::new и ::delete для отслеживания утечек памяти
Позаимствовано отсюда:
https://www.modernescpp.com/index.php/overloading-operator-new-and-delete
Статья устарела - сегодня перегрузок операторов new не 4, а гораздо больше 
*/

#include <iostream>
#include <string>

#include "my_new.h"


class MyClass
{   
    float* p = new float[100];
};

class MyClass2
{
    int five = 5;
    std::string s = "hello";
};


int main()
{
    int* myInt= new int(1998);
    double* myDouble = new double(3.14);
    double* myDoubleArray = new double[2]{1.1,1.2};

    MyClass* myClass = new MyClass;
    MyClass2* myClass2 = new MyClass2;

    delete myDouble;
    delete[] myDoubleArray;
    delete myClass;
    delete myClass2;

    // Автору статьи достаточно было перегрузить operator new и оператор delete
    // Остальные перегрузки операторов new и delete использовали их
    // На g++ 4.9.2 (mingw) потребовалось также перегрузить opеrator new[]
    // и operator delete[]. При этом у автора 7 аллокаций и 5 деаллокаций, 
    // в то время как при воспроизведении опыта с данными поправками 
    // получено 6 аллокаций и 4 деаллокации.
    // Тем не менее, реализовать слежение за утечками памяти путём реализации
    // всех перегрузок операторов new и delete очевидно, возможно
    getInfo();    
}
