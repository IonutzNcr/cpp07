#include <iostream>
#include "iter.hpp"


void print_what(int a)
{
    std::cout << a << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print_what);

    const std::string strs[] = {"hello", "world"};
    iter(strs, 2, printElement<std::string>);
    
    float flts[] = {1.1, 3.3, 23.3};
     iter(flts, 3, printElement<float>);
    return 0;
}