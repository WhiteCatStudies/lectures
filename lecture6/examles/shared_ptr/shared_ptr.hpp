#include <atomic>

// std::atomic_bool


template <class T>
class SharedPtr
{
public:
    SharedPtr() noexcept;
    SharedPtr(T* ptr) noexcept;

    SharedPtr(const SharedPtr<T>& other) noexcept;
    SharedPtr& operator=(const SharedPtr<T>& other) noexcept;

    SharedPtr(SharedPtr<T>&& other) noexcept;
    SharedPtr& operator=(SharedPtr<T>&& other) noexcept;

    ~SharedPtr();

    T& operator*();
    T& operator*() const;

    T* operator->() noexcept;
    T* operator->() const noexcept;

    bool operator==(const SharedPtr<T>& other) const noexcept;
    bool operator==(const T* other) const noexcept;
    bool operator!=(const SharedPtr<T>& other) const noexcept;
    bool operator!=(const T* other) const noexcept;

    void reset(T* newPtr);

    T* get() const noexcept;
    std::uint32_t use_count() const noexcept;

private:
    T* _ptr = nullptr;
    std::uint32_t* _count;

    void _decRef(bool deleteCounter = false);
    void _take(const SharedPtr<T>& other) noexcept;
};

template<class T>
SharedPtr<T>::SharedPtr() noexcept :
    _count(new std::uint32_t(0))
{
}

template<class T>
SharedPtr<T>::SharedPtr(T* ptr) noexcept :
    _ptr(ptr),
    _count(new std::uint32_t(1))
{
}

template<class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& other) noexcept
{
    _take(other);
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other) noexcept
{
    if(other._ptr == _ptr)
    {
        return *this;
    }

    _decRef();
    _take(other);
    return *this;
}

template <class T>
SharedPtr<T>::SharedPtr(SharedPtr<T>&& other) noexcept
{
    _ptr = other._ptr;
    other._ptr = nullptr;

    _count = other._count;
    other._count = nullptr;
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>&& other) noexcept
{
    if(other._ptr == _ptr)
    {
        return *this;
    }
    
    --(*_count);
    if(*_count == 0)
    {
        delete _ptr;
    }

    _ptr = other._ptr;
    other._ptr = nullptr;

    _count = other._count;
    other._count = new std::uint32_t(0);
    
    return *this;
}

template <class T>
T& SharedPtr<T>::operator*()
{
    return *_ptr;
}

template <class T>
T& SharedPtr<T>::operator*() const
{
    return *_ptr;
}

template <class T>
T* SharedPtr<T>::operator->() noexcept
{
    return _ptr;
}

template <class T>
T* SharedPtr<T>::operator->() const noexcept
{
    return _ptr;
}

template <class T>
bool SharedPtr<T>::operator==(const SharedPtr<T>& other) const noexcept
{
    return _ptr == other._ptr;
}

template <class T>
bool SharedPtr<T>::operator==(const T* other) const noexcept
{
    return _ptr == other;
}

template <class T>
bool SharedPtr<T>::operator!=(const SharedPtr<T>& other) const noexcept
{
    return !(this->operator==(other));
}

template<class T>
bool SharedPtr<T>::operator!=(const T* other) const noexcept
{
    return !(this->operator==(other));
}

template<class T>
void SharedPtr<T>::reset(T* newPtr)
{
    if(_ptr == newPtr)
    {
        return;
    }

    _decRef();

    _ptr = newPtr;
    *_count = _ptr != nullptr;
}

template <class T>
T* SharedPtr<T>::get() const noexcept
{
    return _ptr;
}

template <class T>
std::uint32_t SharedPtr<T>::use_count() const noexcept
{
    return *_count;
}

template <class T>
void SharedPtr<T>::_decRef(bool deleteCounter)
{
    if(*_count == 0 || _ptr == nullptr)
    {
        return;
    }

    --(*_count);
    if(*_count == 0)
    {
        delete _ptr;
        _ptr = nullptr;
    }
}

template<class T>
void SharedPtr<T>::_take(const SharedPtr<T>& other) noexcept
{
    _ptr = other._ptr;
    _count = other._count;

    if(_ptr != nullptr)
    {
        ++(*_count);
    }
}

template <class T>
SharedPtr<T>::~SharedPtr()
{
    _decRef();
    if(*_count == 0)
    {
        delete _count;
    }
}

template <class T, class... Args>
SharedPtr<T> makeShared(Args&&... args)
{
    return SharedPtr<T>(new T(args...));
}