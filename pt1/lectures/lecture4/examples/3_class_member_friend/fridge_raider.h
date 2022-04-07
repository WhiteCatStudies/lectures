// header guard гарантирует, что препроцессор вставит заголовочный файл только 1 раз
// #pragma once
// альтернатива #pragma once: #ifndef FILENAME_H #define FILENAME_H #endif  
// #ifndef FRIDGE_RAIDER_H
// #define FRIDGE_RAIDER_H
#include <string>

// опережающее объявление (forward declaration)
// позволяет исползовать тип до того, как он будет объявлен
class Home;

class FridgeRaider
{
public:
	FridgeRaider(const std::string& name);
	// передача параметра по ссылке, в том числе, потому, что ущерб,
	// причинённый расхитителем холодильников, сохраняется
	// после завершения функции
	void raid(Home& home);
private:
	std::string _name;

};
// #endif