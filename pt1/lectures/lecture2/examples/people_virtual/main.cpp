#include <iostream>
#include <string>

#include "young.h"
#include "adult.h"
#include "old.h"

int main(int argc, char* argv[]) {
    
   if (argc != 2)
    {
        std::cout << "Wrong argument count" << std::endl;
        return 1;
    }

    Person* person = nullptr;
    Young young = Young("Wasia");
    Adult adult = Adult("Ania", "MIREA");
    Old old = Old("Frosia");

    std::cout << std::endl;

    const std::string arg = std::string(argv[1]);

    if (arg == "young")
    {
        person = &young;
    }
    else if (arg == "adult")
    {
        person = &adult;
    }
    else if (arg == "old")
    {
        person = &old;
    }
    else
    {
        std::cout << "Wrong argument " << arg << std::endl;
        return 1;
    }

    // Какая версия функции say() будет вызвана, определяет не указатель
    // а объект, на который он ссылается.
    // Объект выбирается во время выполнения программы. Следовательно,
    // версия метода say() определеяется во время выполнения
    person->say();

    getchar();
}
