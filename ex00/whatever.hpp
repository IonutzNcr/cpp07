#ifndef WHATEVER_HPP
#define WHATEVER_HPP


template <class validType>
void swap(validType &a, validType &b)
{
    validType tmp = a;
    a = b;
    b = tmp;
}

template <class T>
T min(T a, T b)
{
    if(a < b)
        return (a);
    else 
        return (b);
}
template <class T>
T max(T a, T b)
{
    if(a > b)
        return (a);
    else 
        return (b);
}

#endif

