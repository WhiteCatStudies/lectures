#include <memory>
#include <string>
#include <iostream>
#include <iomanip>

#include "shared_ptr.hpp"
#include "cat.hpp"


template <class T>
void report(const T& ptr, const std::string& name)
{
    std::cout << std::setw(10) << std::right << name << ": " << ptr.use_count() <<
        " " << ((ptr != nullptr) ? ptr->getName() : "") << std::endl;
}

int main()
{
    std::cout << "Initialization" << std::endl;
    auto ptr = std::make_shared<Cat>("Wasia", "noname", 10, 10, 1);
    auto myPtr = makeShared<Cat>("Wasia", "noname", 10, 10, 1);
    // У каждого Васи по одному владельцу - соответственно ptr и myPtr
    report(ptr, "std::ptr");
    report(ptr, "myptr");

    std::getchar();
    
    std::cout << "Copy construction of shared pointers" << std::endl;
    auto ptr2 = ptr;
    auto myPtr2 = myPtr;
    // У каждого Васи по два владельца - ptr и ptr2, myPtr и myPtr2
    // При этом вась только двое
    report(ptr, "std::ptr");
    report(myPtr, "myptr");
    report(ptr2, "std::ptr2");
    report(myPtr2, "myptr2");

    std::getchar();

    std::cout << "Copy assignment of shared pointers" << std::endl; 
    auto ptr3 = std::make_shared<Cat>("Masia", "noname", 10, 5, 5);
    auto myPtr3 = makeShared<Cat>("Masia", "noname", 10, 5, 5);
    ptr2 = ptr3;
    myPtr2 = myPtr3;
    // ptr2 больше не владелец Васи, у него остался только один вледелец - ptr
    // Зато ptr2 теперь владелец Маси, и всего у Маси два владельца - ptr2 и ptr3
    report(ptr, "std::ptr");
    report(myPtr, "myptr");
    report(ptr2, "std::ptr2");
    report(myPtr2, "myptr2");
    report(ptr3, "std::ptr3");
    report(myPtr3, "myptr3");

    std::getchar();

    std::cout << "Move assignment of shared pointers" << std::endl;
    ptr = std::move(ptr3);
    myPtr = std::move(myPtr3);
    // ptr3 больше ничем не владеет - он отдал все права собственности ptr
    // ptr удаляет свой объект, т.к. он был его единственным вадельцем
    // Итого у Васи нет хозяина, а ptr теперь хозяин Маси вместе с ptr2, т.е.
    // у Маси по-прежнему двое хозяев
    report(ptr, "std::ptr");
    report(myPtr, "myptr");
    report(ptr2, "std::ptr2");
    report(myPtr2, "myptr2");
    report(ptr3, "std::ptr3");
    report(myPtr3, "myptr3");

    // Несмотря на то, что у каждой Маси по два хозяина,
    // деструктор вызывается по одному разу
}