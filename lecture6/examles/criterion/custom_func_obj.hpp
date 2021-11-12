template<class T>
class Add
{
public:
	Add() = default;
	Add(T val): _val(val)
	{}

	void operator()(T& elem)
	{
		elem += _val;
	}

private:
	T _val = 0;
};

class Mean
{
public:
	Mean() = default;

	void operator()(int val)
	{
		_sum += val;
		++_count;
	}

	double value() const
	{
		return _count == 0 ? 0. : static_cast<double>(_sum) / _count;
	}

private:
	int _sum = 0;
	unsigned int _count = 0;
};