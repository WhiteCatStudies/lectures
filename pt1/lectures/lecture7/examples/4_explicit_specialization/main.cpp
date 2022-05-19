#include <iostream>
#include <sstream>
#include <iomanip> // setprecision, boolalpha
#include <string>
#include <limits>  // numeric_limits
#include <math.h>  // M_PI


template<typename T> 
inline std::string stringify(const T& x)
{
    std::ostringstream out;
    out << x;
    return out.str();
}

template<> 
inline std::string stringify<bool>(const bool& x)
{
    std::ostringstream out;
    out << std::boolalpha << x;
    return out.str();
}

template<> 
inline std::string stringify<double>(const double& x)
{
    /* 
    The value of std::numeric_limits<T>::digits10 
    is the number of base-10 digits that can be represented by the type T
    without change, that is, any number with this many significant decimal digits
    can be converted to a value of type T and back to decimal form,
    without change due to rounding or overflow. 
    */
    const int sigdigits = std::numeric_limits<double>::digits10;
    std::ostringstream out;
    out << std::setprecision(sigdigits) << x;
    return out.str();
}

int main()
{
    std::cout << stringify(true) << std::endl;
    std::cout << stringify(M_PI) << std::endl;
    std::cout << stringify(42)   << std::endl;
}