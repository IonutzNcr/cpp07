#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <class T>
class Array
{
    public:
        Array():_size(0)
        {
            arr = NULL;
        }
        Array(unsigned int n) :_size(n)
        {
            if (n)
                arr = new T[n]();
            else
                arr = NULL;
            
        }
        class OutOfBoundException : public std::exception
        {
            public:
                const char *what() const throw(){
                    return ("Out of bounds") ;
                }
        };
        Array(Array &src){
            if (src != *this)
            {
                arr = new T[src._size];
                _size = src._size;
                for (int i = 0; i < _size; i++)
                    arr[i] = src.arr[i];
            }
            return *this;
        }
        Array& operator=(Array &rhs){
            if (rhs != *this)
            {
                delete[] arr;
                arr = new T[rhs._size];
                _size = rhs._size
                for (int i = 0; i < _size; i++)
                    arr[i] = rhs.arr[i];
            }
        }
        T& operator[]( unsigned int x)
        {
            if (x >= _size || x < 0)
                throw OutOfBoundException();
            return (arr[x]);
        }

        const T& operator[]( unsigned int x) const
        {
            if (x >= _size)
                throw OutOfBoundExceptin();
            return (arr[x]);
        }


        ~Array(){
            delete[] arr;
        }
        unsigned int size() const {
            return (_size);
        }
    private:
        unsigned int _size;
        T *arr;
};

#endif