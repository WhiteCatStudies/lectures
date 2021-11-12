#include <vector>
#include <iostream>

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
	for (const auto& elem : vec) 
	{
		os << elem << " ";
	}

	return os;
}