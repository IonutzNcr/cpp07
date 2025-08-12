#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

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
        Array(Array const &src){
            if (&src != this)
            {
                if (!src._size)
                {
                    _size = src._size;
                    arr = NULL;
                }
                else{
                    arr = new T[src._size];
                    _size = src._size;
                    for (unsigned int i = 0; i < _size; i++)
                        arr[i] = src.arr[i];
                }
            }
        }
        Array& operator=(Array const &rhs){
            if (&rhs != this)
            {
                if (_size)
                    delete[] arr;
                if (!rhs._size)
                {
                    arr = NULL;
                    _size = rhs._size;
                }
                else
                {
                    arr = new T[rhs._size];
                    _size = rhs._size;
                    for (unsigned int i = 0; i < _size; i++)
                        arr[i] = rhs.arr[i];
                }
            }
            return *this;
        }
        T& operator[]( unsigned int x)
        {
            if (x >= _size )
                throw OutOfBoundException();
            return (arr[x]);
        }

        const T& operator[]( unsigned int x) const
        {
            if (x >= _size)
                throw OutOfBoundException();
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