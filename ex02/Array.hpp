#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <class T>
class Array
{
    public:
        Array():_size(5)
        {
            arr = new T[5];
        }
        Array(unisgned int n) :_size(n)
        {
            arr = new T[n];
            for(int i = 0; i < n; i++)
                arr[i] = 0;
        }
        class OutOfBoundException()
        {
            const char *what() throw(){
                std::cout << "Out of bounds" ;
            }
        }
        Array(Array<T> &src){
            if (src != *this)
            {
                arr = new T[src._size];
                _size = src._size
                for (i = 0; i < _size; i++)
                    arr[i] = src.arr[i];
            }
        }
        operator=(Array &rhs){
            if (rhs != *this)
            {
                delete arr[];
                arr = new T[rhs._size];
                _size = rhs._size
                for (i = 0; i < _size; i++)
                    arr[i] = rhs.arr[i];
            }
        }
        operator[]( unsigned int x)
        {
            if (x >= size)
                throw OutOfBoundExceptin();
            return (arr[x]);
        }

        ~Array(){
            delete arr[];
        }
        size(){
            return (_size);
        }
    private:
        unsigned int _size;
        T *arr;
};

#endif