template <class T>
class UniquePtr
{
public:
    UniquePtr() = default;
    UniquePtr(T* ptr) noexcept;

    UniquePtr(const UniquePtr<T>& other) = delete;
    UniquePtr& operator=(const UniquePtr<T>& other) = delete;

    UniquePtr(UniquePtr<T>&& other) noexcept;
    UniquePtr& operator=(UniquePtr<T>&& other);

    T& operator*();
    T& operator*() const;
    T* operator->() noexcept;
    T* operator->() const noexcept;

    bool operator==(const UniquePtr<T>& other) const noexcept;
    bool operator==(const T* other) const noexcept;
    bool operator!=(const UniquePtr<T>& other) const noexcept;
    bool operator!=(const T* other) const noexcept;

    ~UniquePtr();

    void reset(const T* other);
    T* release();

private:
    T* _ptr = nullptr;
};

template <class T>
UniquePtr<T>::UniquePtr(T* ptr) noexcept :
    _ptr(ptr)
{
}

template <class T>
UniquePtr<T>::UniquePtr(UniquePtr<T>&& other) noexcept
{
    _ptr = other._ptr;
    other = nullptr;
}

template <class T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other)
{
    if(_ptr == other._ptr)
    {
        return *this;
    }

    delete _ptr;
    _ptr = other._ptr;
    other._ptr = nullptr;
}

template <class T>
T& UniquePtr<T>::operator*()
{
    return *_ptr;
}

template <class T>
T& UniquePtr<T>::operator*() const
{
    return *_ptr;
}

template <class T>
T* UniquePtr<T>::operator->() noexcept
{
    return *_ptr;
}

template <class T>
T* UniquePtr<T>::operator->() const noexcept
{
    return _ptr;
}

template <class T>
bool UniquePtr<T>::operator==(const UniquePtr<T>& other) const noexcept
{
    return (_ptr == other._ptr);
}

template <class T>
bool UniquePtr<T>::operator==(const T* other) const noexcept
{
    return (_ptr == other);
}

template <class T>
bool UniquePtr<T>::operator!=(const UniquePtr<T>& other) const noexcept
{
    return !(this->operator==(other));
}

template <class T>
bool UniquePtr<T>::operator!=(const T* other) const noexcept
{
    return !(this->operator==(other));
}

template <class T>
void UniquePtr<T>::reset(const T* other)
{
    delete _ptr;
    _ptr = other;
}

template <class T>
T* UniquePtr<T>::release()
{
    auto tmp = _ptr;
    _ptr = nullptr;
    return tmp;
}

template <class T>
UniquePtr<T>::~UniquePtr()
{
    delete _ptr;
}

template <class T, class... Args>
UniquePtr<T> makeUnique(Args&&... args)
{
    return UniquePtr<T>(new T(args...));
}