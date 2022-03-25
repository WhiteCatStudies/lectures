// tuple - рекурсивная структура данных!
// Опережающее определение для наследования
template<class... Args>
struct tuple;

// База рекурсии
template<>
struct tuple<>
{};

template<class Head, class... Tail>
struct tuple<Head, Tail...> : tuple<Tail...>
{
    // struct tuple<Head, Tail...> наследуется от tuple<Tail...> 
    // (это другой тип, т.к имеет другие формальные параметры шаблона)
    // Значение первого типа "оставляет себе", а остальные передаёт конструктору
    // базового класса
    tuple(Head h, Tail... tail)
        : tuple<Tail...>(tail...),
          head(h)
    {}
    typedef tuple<Tail...>  base_type;
    typedef Head            value_type;
    
    base_type& base = static_cast<base_type&>(*this);
    Head       head;
};

// Структура нужна, чтобы обойти запрет на частичную специализацию
// шаблонных функций
template<int I, class Head, class... Args>
struct getter
{
    typedef typename getter<I-1, Args...>::return_type return_type;

    static return_type get(tuple<Head, Args...> t)
    {
        return getter<I-1, Args...>::get(t);
    }
};

// База рекурсии
template<class Head, class... Args>
struct getter<0, Head, Args...>
{
    typedef typename tuple<Head, Args...>::value_type return_type;

    static return_type get(tuple<Head, Args...> t)
    {
        return t.head;
    }
};

// Позволяет вызывать getter, передавая ему только номер требуемого элемента - 
// остальные формальные (типовые) параметры шаблона выведутся из параметра функции
template<int I, class Head, class... Args>
typename getter<I, Head, Args...>::return_type get(tuple<Head, Args...> t)
{
    return getter<I, Head, Args...>::get(t);
}