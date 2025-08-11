#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>

template <class T,  class F >
void iter(T arr, size_t size, F func)
{
    for (size_t i = 0; i < size; ++i)
        func(arr[i]);
}

template <typename T>
void printElement(const T& x) {
    std::cout << x << std::endl;
}



#endif