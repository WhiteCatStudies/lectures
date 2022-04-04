#include <vector>
#include <list>
#include <deque>
#include <set>
#include <array>
#include <set>

#include <iostream>

template <class InputIterator>
std::ostream& print(std::ostream& os, InputIterator first, InputIterator last)
{
	while(first != last)
	{
		os << *first++ << " "; 
	}

	return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
	return print(os, vec.cbegin(), vec.cend());
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& lst)
{
	return print(os, lst.cbegin(), lst.cend());
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::deque<T>& dq)
{
	return print(os, dq.cbegin(), dq.cend());
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st)
{
	return print(os, st.cbegin(), st.cend());
}

template <class T, size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr)
{
	return print(os, arr.cbegin(), arr.cend());
}