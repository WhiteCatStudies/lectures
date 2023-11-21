#include <memory>
#include <string>
#include <iostream>
#include <iomanip>

#include "shared_ptr.hpp"
#include "cat.hpp"


template <class T>
void reportOwner(const T& ptr, const std::string& name)
{
    std::cout << std::setw(10) << std::right << name << " owns "
        << ((ptr != nullptr) ? ptr->getName() : "nobody") << '\n';
}

void reportTotalOwners(const std::shared_ptr<Cat>& ptr)
{
    std::cout << "Total owners count of " << 
        ((ptr != nullptr) ? ptr->getName() : "nobody") << ": " << 
        ptr.use_count() << '\n';
}

int main()
{
    std::cout << "Initialization" << std::endl;
    auto ptr = std::make_shared<Cat>("Wasia", "noname", 10, 10, 1);
    // У Васи один владелец - std::ptr
    reportOwner(ptr, "std::ptr");
    reportTotalOwners(ptr);

    std::getchar();
    
    std::cout << "Copy construction of shared pointers" << std::endl;
    auto ptr2 = ptr;
    // У Васи два владельца - ptr и ptr2. Сам Вася один
    reportOwner(ptr, "std::ptr");
    reportOwner(ptr2, "std::ptr2");
    reportTotalOwners(ptr);
    std::getchar();

    std::cout << "Copy assignment of shared pointers" << std::endl; 
    auto ptr3 = std::make_shared<Cat>("Masia", "noname", 10, 5, 5);
    ptr2 = ptr3;
    // ptr2 больше не владелец Васи, у него остался только один вледелец - ptr
    // Зато ptr2 теперь владелец Маси, и всего у Маси два владельца - ptr2 и ptr3
    reportOwner(ptr, "std::ptr");
    reportOwner(ptr2, "std::ptr2");
    reportOwner(ptr3, "std::ptr3");
    reportTotalOwners(ptr);
    reportTotalOwners(ptr3);

    std::getchar();

    std::cout << "Move assignment of shared pointers" << std::endl;
    ptr = std::move(ptr3);
    // ptr3 больше ничем не владеет - он отдал все права собственности ptr
    // ptr удаляет свой объект, т.к. он был его единственным вадельцем
    // Итого у Васи нет хозяина, а ptr теперь хозяин Маси вместе с ptr2, т.е.
    // у Маси по-прежнему двое хозяев
    reportOwner(ptr, "std::ptr");
    reportOwner(ptr2, "std::ptr2");
    reportOwner(ptr3, "std::ptr3");
    reportTotalOwners(ptr);
    reportTotalOwners(ptr2);


    std::getchar();
    // Несмотря на то, что у каждой Маси по два хозяина,
    // деструктор вызывается по одному разу
}