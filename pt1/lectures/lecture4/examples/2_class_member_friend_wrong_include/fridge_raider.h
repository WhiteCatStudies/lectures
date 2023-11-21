// Этот пример не компилируется из-за рекурсивного включения заголовков
// fridge_raider.h и home.h
#include <string>

#include "home.h"


class FridgeRaider
{
public:
  FridgeRaider(const std::string& name);
  // передача параметра по ссылке, потому что ущерб,
  // причинённый расхитителем холодильников, сохраняется
  // после завершения функции
  void raid(Home& home);
private:
  std::string _name;
};