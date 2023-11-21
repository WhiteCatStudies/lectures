#include <forward_list>
#include <iostream>

template <class T>
std::ostream& operator<<(std::ostream& ostr, const std::forward_list<T>& list)
{
    for (auto &i : list) 
    {
        ostr << i << " ";
    }

    return ostr;
}


int main()
{
	std::forward_list<int> flist{1, 2, 3, 4, 5}; 
	
	std::cout << "Before insert: " << flist;
	auto beforeBegIt = flist.before_begin();
	flist.insert_after(beforeBegIt, 42);
	std::cout << "\nAfter insert: " << flist;
}