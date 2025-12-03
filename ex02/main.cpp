#include <iostream>
#include "Array.hpp"

int main(void) {
    try {
        std::cout << "=== Default constructor ===" << std::endl;
        Array<int> a;
        std::cout << "Size: " << a.size() << std::endl;

        std::cout << "\n=== Accessing dock ===" << std::endl;
        int * dock = new int();
        std::cout << *dock << std::endl;
        delete dock;

        std::cout << "\n=== Constructor with size ===" << std::endl;
        Array<int> b(5);
        std::cout << "\n=== Printing actual elements" << "\n";
        std::cout << "Size: " << b.size() << std::endl;
        for (unsigned int i = 0; i < b.size(); ++i) {
            std::cout << "b[" << i << "] = " << b[i] << std::endl;
        }
        std::cout << "\n=== Modifying elements" << "\n";
        for (unsigned int i = 0; i < b.size(); ++i) {
            b[i] = i * 10; 
            std::cout << "b[" << i << "] = " << b[i] << std::endl;
        }

        std::cout << "\n=== Copy constructor ===" << std::endl;
        Array<int> c(b);
        for (unsigned int i = 0; i < c.size(); ++i)
            std::cout << "c[" << i << "] = " << c[i] << std::endl;

        std::cout << "\n=== Assignment operator ===" << std::endl;
        Array<int> d;
        d = b;
        for (unsigned int i = 0; i < d.size(); ++i)
            std::cout << "d[" << i << "] = " << d[i] << std::endl;

        std::cout << "\n=== Modify copy and check independence ===" << std::endl;
        c[0] = 999;
        std::cout << "c[0] = " << c[0] << std::endl;
        std::cout << "b[0] = " << b[0] << " (should be unchanged)" << std::endl;

        std::cout << "\n=== Const access ===" << std::endl;
        const Array<int> e(b);
        std::cout << "e[2] = " << e[2] << std::endl;

        std::cout << "\n=== Out-of-bounds test ===" << std::endl;
        std::cout << "Trying to access index 10 in array of size " << b.size() << std::endl;
        std::cout << b[10] << std::endl;

    } catch (const Array<int>::OutOfBoundException &err) {
        std::cerr << err.what() << std::endl;
    } catch (const std::exception &err) {
        std::cerr << "Caught std::exception: " << err.what() << std::endl;
    }

     try {
        std::cout << "\n=== Testing with char ===" << std::endl;
        Array<char> letters(5);
        for (unsigned int i = 0; i < letters.size(); ++i) {
            letters[i] = 'A' + i;
            std::cout << "letters[" << i << "] = " << letters[i] << std::endl;
        }

        std::cout << "\n=== Copy constructor with char ===" << std::endl;
        Array<char> lettersCopy(letters);
        for (unsigned int i = 0; i < lettersCopy.size(); ++i)
            std::cout << "lettersCopy[" << i << "] = " << lettersCopy[i] << std::endl;

        std::cout << "\n=== Modify copy and check independence (char) ===" << std::endl;
        lettersCopy[0] = 'Z';
        std::cout << "lettersCopy[0] = " << lettersCopy[0] << std::endl;
        std::cout << "letters[0] = " << letters[0] << " (should be unchanged)" << std::endl;

        std::cout << "\n=== Out-of-bounds test (char) ===" << std::endl;
        std::cout << letters[10] << std::endl;

    } catch (const Array<char>::OutOfBoundException &ex) {
        std::cerr << "Caught Array<char>::OutOfBoundException: " << ex.what() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Caught std::exception: " << ex.what() << std::endl;
    }

    return 0;
}
