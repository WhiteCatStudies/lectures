#include <deque>
#include <string>
#include <iostream>

template<class T>
std::ostream& operator<<(std::ostream& ostr, const std::deque<T>& deque)
{
    for (auto &i : deque) {
        ostr << " " << i;
    }
    return ostr;
}

template<class T, class Iter>
void printInsertMessage(int ins, const std::deque<T>& deque,  Iter& it)
{
	std::cout << "Insert " << ins << " to the beginning\n" << deque << 
		"\nControl element at " << " has address " << *(--it) << std::endl;
}


int main()
{
	std::deque<std::string> testDeque{"Lorem Ipsum is simply dummy text of the " \
									  "printing and typesetting industry.",
									  "Lorem Ipsum has been the industry\'s standard "\
									  "dummy text ever since the 1500s",
									  "when an unknown printer took a galley of type " \
									  "and scrambled it to make a type specimen book",
									  "It has survived not only five centuries"};

	const auto testIt = testDeque.cbegin();
	const std::string midStr = "The iterators should be invalidated by insertion " \
							   "because it is a deque\n" \
							   "Where does the old iterator point? Who knows?";

	// Итератор testIt не знает, что происходит с testDeque в дальнейшем
	// Он по-прежнему указывает на первый элемент первого блока, в то время как 
	// Порядок элементов и внутренняя нумерация блоков могли измениться 
	for(int i = 0; i < 20; ++i)
	{
		testDeque.insert(testDeque.begin() + 2, std::to_string(i) + ": " + midStr);
		std::cout << "Inserted in the middle " << (i + 1) << " times" << '\n' << 
			"Begin points to \"" << *testIt << "\"" << std::endl;
	}

	std::getchar();	
}
