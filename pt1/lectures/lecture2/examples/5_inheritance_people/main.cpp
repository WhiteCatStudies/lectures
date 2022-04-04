#include <iostream>

#include "young.h"
#include "adult.h"
#include "old.h"

int main() {
    Young young = Young("Wasya");
    Adult adult = Adult("Anya", "MIREA");
    Old old = Old("Frosia");
    std::cout << std::endl;

    young.say();
    young.sayMoney();
    young.sayTime();
    young.sayEnergy();
    young.goStudy();
    std::cout << std::endl;

    adult.say();
    adult.goWork();
    adult.sayTime();
    adult.sayEnergy();
    adult.sayMoney();
    std::cout << std::endl;

    old.say();
    old.sayTime();
    old.sayMoney();
    old.sayEnergy();
    old.goFeedPegeons();
    std::cout << std::endl;
}
