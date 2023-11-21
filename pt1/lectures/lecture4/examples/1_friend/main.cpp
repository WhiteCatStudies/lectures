#include "home.h"

#include <iostream>


void raid(Home& home)
{
    std::cout << "Hello! I am Fridge Raider!" << std::endl;
    const std::string food  = home._fridge.get();
    const std::string foodName = food.empty() ? "nothing" : food;
    std::cout << "I found some " << food << " in your fridge. Now its mine!" <<
        std::endl;
}

int main()
{
    std::cout << "Lets go home and put some food in our fridge" << std::endl;
    const size_t fridgeSize = 10;
    Home home(fridgeSize);
    std::getchar();

    raid(home);
}