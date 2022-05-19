int sum(int first, int second)
{
	return first + second;
}

// template definition
template <class T>
T sumTemplate(T first, T second)
{
	return first + second;
}

int main()
{
	// template specializations
	// sumTemplate(1,2);
	// sumTemplate(1.5, 2.);
}
