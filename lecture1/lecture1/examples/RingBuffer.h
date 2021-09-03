#pragma once

#include <iterator>
#include <vector>

template <class T>
class RingIterator;

template<class T>
struct std::iterator_traits<RingIterator<T>>
{
	typedef std::ptrdiff_t						difference_type;
	typedef T									value_type;
	typedef T&									reference;
	typedef T*									pointer;
	typedef std::random_access_iterator_tag		iterator_category;
};

template <class T>
class RingIterator
{
public:
	RingIterator<T>& operator+=(int n);
	RingIterator<T>  operator+ (int n) const;
	RingIterator<T>& operator-=(int n);
	RingIterator<T>  operator- (int n) const;
	typename std::iterator_traits<RingIterator<T>>::difference_type
		operator- (const RingIterator<T>& other) const;
	RingIterator<T>& operator[](int n);
	RingIterator<T>& operator ++ ();
	RingIterator<T>  operator ++ (int);
	RingIterator<T>& operator -- ();
	RingIterator<T>  operator -- (int);

	bool operator <  (const RingIterator<T>& other) const;
	bool operator >  (const RingIterator<T>& other) const;
	bool operator <= (const RingIterator<T>& other) const;
	bool operator >= (const RingIterator<T>& other) const;
	bool operator == (const RingIterator<T>& other) const;
	bool operator != (const RingIterator<T>& other) const;

	typename std::iterator_traits<RingIterator<T>>::reference operator*()  const;
	typename std::iterator_traits<RingIterator<T>>::pointer   operator->() const;

	template <class T>
	friend class RingBuffer;

private:
	RingIterator(const typename std::vector<T>::iterator& it,
				 const typename std::vector<T>::iterator& last,
				 const typename std::vector<T>::iterator& vBeg,
				 const typename std::vector<T>::iterator& vEnd);

	RingIterator() = default;

	typename std::vector<T>::iterator		_it;
	typename std::vector<T>::iterator		_last;		//iterator on the last added element 
	typename std::vector<T>::iterator		_vBeg;		//underlying vector begin
	typename std::vector<T>::iterator		_vEnd;		//underlying vector end

	void moveToTheLatestElement();
	typename std::iterator_traits<RingIterator<T>>::difference_type
		fromCurrentToEnd(const typename std::vector<T>::iterator& it) const;
};

template <class T>
RingIterator<T>::RingIterator(const typename std::vector<T>::iterator& it,
							  const typename std::vector<T>::iterator& last,
							  const typename std::vector<T>::iterator& vBeg,
							  const typename std::vector<T>::iterator& vEnd)
	: _it(it)
	, _last(last)
	, _vBeg(vBeg)
	, _vEnd(vEnd)
{
}

template <class T>
RingIterator<T>& RingIterator<T>::operator += (int n)
{
	if (n == 0)
	{
		return *this;
	}

	if (_vEnd - _vBeg <= 1) 
	{
		//the underlying vector has no place to move the iterator to
		_it = _vEnd;
		_ASSERT(false);
		return *this;
	}

	const std::ptrdiff_t lastDist = abs(_it - _last);
	const std::ptrdiff_t begDist = _it - _vBeg;

	if (n > 0)
	{
		//the iterator is being moved in the cycle's positive direction
		const int toEnd = static_cast<int>(fromCurrentToEnd(_it));

		if (_it == _vEnd || n > toEnd)
		{
			//can't move forward if the end is already reached
			_it = _vEnd;
			_ASSERT(false);
			return *this;
		}

		if (_it <= _last && n > begDist)
		{
			_it = _vEnd - (n - begDist);
		}
		else if (n == toEnd)
		{
			_it = _vEnd;
		}
		else
		{
			_it -= n;
		}
	}
	else
	{
		// n < 0, the iterator is being moved in the cycle's negative direction
		const std::ptrdiff_t toLast = _it <= _last ?
			(_last - _it) : ((_vEnd - _it) + (_last - _vBeg));

		int nMod = abs(n);

		if (_it == _last || nMod > toLast)
		{
			//can't move backwards because the beginnig is already reached
			//or n is too big
			_it = _vEnd;
			_ASSERT(false);
			return *this;
		}

		if (_it == _vEnd)
		{
			moveToTheLatestElement();
			--nMod;
		}

		if (nMod != 0)
		{
			const std::ptrdiff_t endDist = _it - _vEnd - 1;
			nMod <= endDist ? _it += n : _it = _vBeg + n - endDist;
		}
	}

	return *this;
}

template <class T>
inline
RingIterator<T> RingIterator<T>::operator + (int n) const 
{
	RingIterator<T> temp = *this;
	temp += n;
	return temp;
}

template <class T>
inline
RingIterator<T>&  RingIterator<T>::operator -= (int n)
{
	return *this += -n;
}

template <class T>
inline
RingIterator<T> RingIterator<T>::operator - (int n) const
{
	RingIterator<T> temp = *this;
	temp -= n;
	return temp;
}

template <class T>
typename std::iterator_traits<RingIterator<T>>::difference_type
RingIterator<T>::operator - (const RingIterator<T>& other) const
{
	if (_vEnd - _vBeg <= 1)
	{
		//the underlying vector has no place to move the iterator to
		_ASSERT(false);
		return 0;
	}

	const typename std::vector<T>::iterator otherIt = other._it;

	if (_it == _vEnd)
	{
		return fromCurrentToEnd(otherIt);
	}

	if (otherIt == _vEnd)
	{
		return -fromCurrentToEnd(_it);
	}

	if (_it <= _last && otherIt > _last)
	{
		//our iterator lyes to the left from the last added element,
		//another one - to the right
		return (_vBeg - _it) - (_vEnd - otherIt);
	}
	else if (otherIt <= _last && _it > _last)
	{
		//our iterator lyes to the right from the last added element,
		//another one - to the left
		return (otherIt - _vBeg) + (_vEnd - _it);
	}
	else
	{
		//on one side or equal
		return other._it - _it;
	}
}

template <class T>
RingIterator<T>& RingIterator<T>::operator[](int n) 
{
	RingIterator<T> temp = *this;
	return *(temp + n);
}

template <class T>
RingIterator<T>& RingIterator<T>::operator++()
{
	if (_it == _vEnd || _vEnd - _vBeg <= 1)
	{
		//already at the end, vector is empty or it has only one element
		//can't go further
		_ASSERT(false);
		return *this;
	}

	if (_it == _vBeg)
	{
		_it = _vEnd - 1;
	}
	else
	{
		--_it;
	}

	if (_it == _last)
	{
		//the last added element reached, iterations completed
		_it = _vEnd;
	}

	return *this;
}

template <class T>
RingIterator<T> RingIterator<T>::operator++(int)
{
	const RingIterator<T> temp = *this;
	++*this;
	return temp;
}

template <class T>
RingIterator<T>& RingIterator<T>::operator--()
{
	if (_it == _last || _vEnd - _vBeg <= 1)
	{
		//already at the beginning, vector is empty or it has only one element
		//can't go backwards
		_ASSERT(false);
		return *this;
	}

	if (_it == _vEnd)
	{
		moveToTheLatestElement();
		return *this;
	}

	if (_it == _vEnd - 1)
	{
		_it = _vBeg;
	}
	else
	{
		++_it;
	}

	if (_it == _last + 1)
	{
		_it = _vEnd;
	}

	return *this;
}

template <class T>
RingIterator<T> RingIterator<T>::operator--(int)
{
	const RingIterator<T> temp = *this;
	--*this;
	return temp;
}

template <class T>
inline
bool RingIterator<T>::operator < (const RingIterator<T>& other) const
{
	if (_it <= _last && other._it <= _last ||
		_it  > _last && other._it  > _last)
	{
		//iterators on different sides from the last added element
		//the greater in std::vector is the less here
		return !(_it >= other._it);
	}

	return _it < other._it;
}

template <class T>
inline
bool RingIterator<T>::operator > (const RingIterator<T>& other) const
{
	return !(*this < other || _it == other._it);
}

template <class T>
inline
bool RingIterator<T>::operator <= (const RingIterator<T>& other) const
{
	return !(_it > other._it);
}

template <class T>
inline
bool RingIterator<T>::operator >= (const RingIterator<T>& other) const
{
	return !(_it < other._it);
}

template <class T>
inline
bool RingIterator<T>::operator==(const RingIterator<T>& other) const
{
	return _it == other._it;
}

template <class T>
inline
bool RingIterator<T>::operator!=(const RingIterator<T>& other) const
{
	return _it != other._it;
}

template <class T>
inline
typename std::iterator_traits<RingIterator<T>>::reference RingIterator<T>::operator*() const
{
	return *_it;
}

template <class T>
inline
typename std::iterator_traits<RingIterator<T>>::pointer
RingIterator<T>::operator->() const
{
	return _it.operator->();
}

template <class T>
inline
void RingIterator<T>::moveToTheLatestElement()
{
	_last == _vEnd - 1 ? _it = _vBeg : _it = _last + 1;
}

template <class T>
inline
typename std::iterator_traits<RingIterator<T>>::difference_type
RingIterator<T>::fromCurrentToEnd(const typename std::vector<T>::iterator& it) const
{
	return it <= _last ? ((it - _vBeg) + (_vEnd - _last)) : (it - _last);
}

template <class T>
class RingBuffer
{
public:
	using iterator = RingIterator<T>;

	RingBuffer() = default;
	RingBuffer(size_t size);

	void push(const T& val);
	T& operator()(const T& val);

	size_t size() const;
	void resize(size_t newSize);

	const T& operator[](size_t index) const;
	T& operator[](size_t index);
	const T& at(size_t index) const;

	void reset(const T& val = T());

	iterator begin();
	iterator end();

private:
	size_t				_size	 = 0;
	size_t				_current = 0;
	std::vector<T>		_data;
};

template <class T>
RingBuffer<T>::RingBuffer(size_t size)
{
	_data.resize(size);
	_size = size;
}

template <class T>
void RingBuffer<T>::push(const T& val)
{
	_data[_current] = val;
	_current == _size - 1 ? _current = 0 : ++_current;
}

template <class T>
T& RingBuffer<T>::operator()(const T& val)
{
	T prevVal = _data[_current];
	push(val);
	return prevVal;
}

template <class T>
size_t RingBuffer<T>::size() const
{
	return _size;
}

template <class T>
void RingBuffer<T>::resize(size_t newSize)
{
	_data.clear();

	try
	{
		_data.resize(newSize);
	}
	catch (...)
	{
		_size = 0;
		_current = 0;
		return;
	}
	_size = newSize;
}

template<class T>
const T& RingBuffer<T>::operator[](size_t index) const
{
	const size_t end = _size - 1;

	if (index > end)
	{
		_ASSERT(false);
	}

	const size_t retInd = (_current > index) ? (_current - 1 - index) :
		(end + _current - index);

	return _data[retInd];
}

template <class T>
T& RingBuffer<T>::operator[](size_t index)
{
	return const_cast<T&>((*const_cast<const RingBuffer<T> *>(this))[index]);
}

template <class T>
inline
const T& RingBuffer<T>::at(size_t index) const
{
	return this[index];
}

template <class T>
void RingBuffer<T>::reset(const T& val)
{
	_data.assign(_size, val);
	_current = 0;
}

template <class T>
RingIterator<T> RingBuffer<T>::begin()
{
	//current iterator points to the last added element,
	//so the first two arguments are the same here
	if (_current == 0)
	{
		//last added element is at the last position in the vector
		return RingIterator<T>(_data.end() - 1,  //current iterator position
							   _data.end() - 1,  //last added element iterator
							   _data.begin(), _data.end()); //underlying vector begin and end iterators
	}
	else
	{
		return RingIterator<T>(_data.begin() + _current - 1, 
							   _data.begin() + _current - 1, 
							   _data.begin(), _data.end()); 
	}
}

template <class T>
RingIterator<T> RingBuffer<T>::end()
{
	//position is out of cycle. Indicating, that the iterations have reached
	//the point the cycle starts
	if (_current == 0)
	{
		return RingIterator<T>(_data.end(),		//current iterator position
							   _data.end() - 1, //last added element iterator
							   _data.begin(), _data.end());
	}
	else
	{
		return RingIterator<T>(_data.end(),					 //current iterator position
							   _data.begin() + _current - 1, //last added element iterator
							   _data.begin(), _data.end());
	}
}
