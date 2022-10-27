

#include <stddef.h> //size_t, ptrdiff_t
#include <iostream>
#include <iterator> //iterator_traits
#include <algorithm>


template <class T>
class MyIt;


template <class T>
struct std::iterator_traits<MyIt<T>>
{
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::random_access_iterator_tag;
};


template <class T>
class MyIt
{
public:
    MyIt() = default;
    MyIt(T* ptr): _ptr(ptr)
    {}; 

    MyIt<T> operator+(const size_t i) const
    {
        return MyIt(_ptr + i); 
    };

    friend MyIt<T> operator+(size_t i, const MyIt<T>& it)
    {
        return MyIt<T>(it._ptr + i);
    };

    MyIt<T>& operator+=(size_t i)
    {
        _ptr += i;
        return *this;
    };

    MyIt<T>& operator-=(size_t i)
    {
        _ptr -= i;
        return *this;
    };

    MyIt<T>& operator++()
    {
        ++_ptr;
        return *this;
    };

    MyIt<T> operator++(int notUsed)
    {
        const auto tmp = *this;
        ++_ptr;
        return this;
    };

    MyIt<T>& operator--()
    {
        --_ptr;
        return *this;
    };

    MyIt<T> operator--(int notUsed)
    {
        const auto tmp = *this;
        --_ptr;
        return tmp;
    };

    MyIt<T> operator-(size_t i) const
    {
        return MyIt(_ptr - i);
    };

    typename std::iterator_traits<MyIt<T>>::difference_type
    operator-(const MyIt<T>& it) const
    {
        return (_ptr - it._ptr);
    };

    typename std::iterator_traits<MyIt<T>>::pointer
    operator->() 
    {
        return _ptr;
    };

    typename std::iterator_traits<MyIt<T>>::reference
    operator*()
    {
        return *_ptr;
    };

    bool operator==(const MyIt<T>& other) const
    {
        return (_ptr == other._ptr);
    };

    bool operator!=(const MyIt<T>& other) const
    {
        return !(this->operator==(other));
    };

    bool operator<(const MyIt<T>& other) const
    {
        return (_ptr < other._ptr);
    };

    bool operator<=(const MyIt<T>& other) const
    {
        return (_ptr <= other._ptr);
    };

    bool operator>(const MyIt<T>& other) const
    {
        return (_ptr > other._ptr);
    };

    bool operator>=(const MyIt<T>& other) const
    {
        return (_ptr >= other._ptr);
    };

private:
    T* _ptr = nullptr;
};


template <class T>
class MyVector
{
public:
    using iterator = MyIt<T>;

    MyVector() = default;

    MyVector(const MyVector<T>& other)
    {
        _size = other._size;
        _capacity = other._capacity;
        _arr = new T[_capacity];
        
        _copy(other._arr, _arr);
    };

    MyVector(MyVector<T>&& other) noexcept
    {
        _size = other._size;
        _capacity = other._capacity;
        _arr = other._arr;
        other._arr = nullptr;
    };

    void push_back(const T& elem)
    {
        if(_capacity == 0)
        {
            _capacity = 2;
            _arr = new T[_capacity];
        }
        
        if(_size >= _capacity)
        {
            _capacity *= growthFactor;
            auto tmp = new T[_capacity];
            _copy(_arr, tmp);

            delete[] _arr;
            _arr = tmp;
        }

        ++_size;
        _arr[_size - 1] = elem;
    };

    T pop_back()
    {
        auto back = _arr[_size - 1];
        --_size;
        return back;
    };

    T front() const
    {
        return _arr[0];
    };

    T back() const
    {
        return _arr[_size - 1];
    };

    T empty() const noexcept
    {
        return _size == 0;
    };

    void clear() noexcept
    {
        _size = 0;
    };

    size_t size() const noexcept
    {
        return _size;
    };

    size_t capacity() const noexcept
    {
        return _capacity;
    };

    iterator begin() const
    {
        return MyIt<T>(_arr);
    };

    iterator end() const
    {
        return MyIt<T>(_arr + _size);
    };

    MyVector<T>& operator=(const MyVector<T>& other)
    {
        delete[] _arr;

        _size = other._size;
        _capacity = other._capacity;
        _arr = new T[_capacity];
        _copy(other._arr, _arr);
    };

    MyVector<T>& operator=(MyVector<T>&& other)
    {
        delete[] _arr;

        _size = other._size;
        _capacity = other._capacity;
        _arr = other._arr;
        other._arr = nullptr;
    };

    typename std::iterator_traits<MyIt<T>>::reference
    operator[](size_t i)
    {
        return _arr[i];
    };

    typename std::iterator_traits<MyIt<T>>::reference
    operator[](size_t i) const
    {
        return _arr[i];
    };

    ~MyVector()
    {
        delete[] _arr;
    };

private:
    void _copy(T* source, T* dest)
    {
        for(size_t i = 0; i < _size; ++i)
        {
            dest[i] = source[i];
        }
    };

    T* _arr = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

    static const size_t growthFactor = 2;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& vec)
{
    //for (size_t i = 0; i < vec.size(); ++ i)
    //{
    //    os << vec[i] << "; ";
    //}

    for(const auto& v: vec)
    {
        os << v << "; ";
    }
    return os; 
}

template <class T>
void report(const MyVector<T>& vec)
{
    std::cout << vec << '\n' <<
        "Size: " << vec.size() << '\n' <<
        "Capacity: " << vec.capacity() << std::endl; 
}

int main()
{
    MyVector<int> vec;

    vec.push_back(1);
    report(vec);
    std::getchar();

    vec.push_back(5);
    report(vec);
    std::getchar();

    vec.push_back(31);
    report(vec);
    std::getchar();

    vec.push_back(40);
    report(vec);
    std::getchar();

    vec.push_back(8);
    report(vec);
    std::getchar();

    auto third = vec.begin() + 2;
    *third = 42;
    report(vec);
    std::getchar();

    std::cout << "Sorted" << std::endl;
    std::sort(vec.begin(), vec.end());
    report(vec);
}