#include "fridge_raider.h"

#include <iostream>

FridgeRaider::FridgeRaider(const std::string& name): 
  _name(name)
{
  std::cout << "Hello! I am " << _name << " the fridge raider!" << std::endl;
}

void FridgeRaider::raid(Home& home)
{
  const std::string food  = home._fridge.get();
  const std::string foodName = food.empty() ? "nothing" : food;
  std::cout << "I found some " << food << " in your fridge" << std::endl;
}