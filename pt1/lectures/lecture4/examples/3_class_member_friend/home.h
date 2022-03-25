#include "fridge.h"
#include "fridge_raider.h"


class Home
{
public:
	Home(size_t fridgeSize);
	friend void FridgeRaider::raid(Home& home);

private:
	Fridge _fridge;
};