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
    young.sayMoney();
    young.sayTime();
    young.sayEnergy();
    young.goStudy();
    std::getchar();

    adult.say();
    adult.goWork();
    adult.sayTime();
    adult.sayEnergy();
    adult.sayMoney();
    std::getchar();

    old.say();
    old.sayTime();
    old.sayMoney();
    old.sayEnergy();
    old.goFeedPegeons();
    std::getchar();
}
