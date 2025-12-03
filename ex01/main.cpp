#include "iter.hpp"


static void print_what(const int a)
{
    std::cout << a << std::endl;
}

static void increment (int &a)
{
    a += 1;
}



int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    ::iter(arr, 5, print_what);
    std::cout << "After incrementing:" << "\n";
    ::iter(arr, 5, increment);
    ::iter(arr, 5, print_what);
    std::cout << "-------------------" <<  "\n";
    const std::string strs[] = {"hello", "world"};
    ::iter(strs, 2, printElement<std::string>);
    
    float flts[] = {1.1, 3.3, 23.3};
    ::iter(flts, 3, printElement<float>);

    const   double dbls[] = {1.11, 2.22, 3.33};
    ::iter(dbls, 3, printElements<const double>);
    return 0;
}