#include <iostream>

#include "young.h"
#include "adult.h"
#include "old.h"

int main() {
    Young young = Young("Wasya");
    Adult adult = Adult("Anya", "MIREA");
    Old old = Old("Frosia");
    std::getchar();

    young.say();
    young.act();
    young.sayMoney();
    young.sayTime();
    young.sayEnergy();
    std::getchar();

    adult.say();
    adult.act();
    adult.sayTime();
    adult.sayEnergy();
    adult.sayMoney();
    std::getchar();

    old.say();
    old.act();
    old.sayTime();
    old.sayMoney();
    old.sayEnergy();
    std::getchar();
}
