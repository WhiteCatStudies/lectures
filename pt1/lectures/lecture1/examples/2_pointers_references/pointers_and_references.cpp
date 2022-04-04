#include <iostream>

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

char& ith(char* s, int i) {
    return s[i];
}

int main() {

    int var = 3;
    // Здесь & - ссылка
    // Берем адрес переменной var в памяти и записываем его в переменную ref
    int& ref = var;
    int* refptr = &ref;
    // Записываем 5 по адресу переменной var
    ref = 5;
    // Здесь & - оператор взятия адреса
    int* ptr = &var;
    std::getchar();

    // Не нужно разыменовывать ссылку, чтобы получить значение переменной 
    std::cout << "refptr=" << refptr << std::endl;
    std::cout << "*refptr=" << *refptr << std::endl;
    std::cout << "var=" << var << std::endl;
    std::cout << "ref=" << ref << std::endl;
    std::cout << "ptr=" << ptr << std::endl;
    std::cout << "*ptr=" << *ptr << std::endl;
    std::getchar();

    // Ссылка также не может быть нулевой
    // В остальном ссылка аналогичная константному указателю:
    // не поддерживает арифметические операции, 
    // должна быть инициализирована при объявлении

    // В функцию можно передавать параметры по ссылке
    std::cout << "Testing swap function" << std::endl;    
    int x = 10, y = 20;
    std::cout << "Before" << std::endl;    
    std::cout << "x=" << x << " y=" << y << std::endl;    
    swap(x, y);
    std::cout << "After" << std::endl;    
    std::cout << "x=" << x << " y=" << y << std::endl;    
    std::getchar();

    // Функция может возвращать ссылку, но нужно быть уверенным,
    // что переменная, на которую Вы ссылаетесь, не выйдет из области видимости
    std::cout << "Testing function returning reference" << std::endl;    
    char s[] = "qwerty";
    ith(s, 2) = 'x';
    std::cout << s << std::endl;

    getchar();
}
