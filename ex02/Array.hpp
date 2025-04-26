#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstddef>
#include <stdlib.h>

/* Color Sets */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;250m"

template <typename T>
class Array {
private:
    /* member attributes */
    unsigned int    _size;
    T*              _data;
public:
    /* Orthodox Canonical Form (OCF) */
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();
    Array& operator=(const Array& other);

    T&          operator[](unsigned int idx);
    T const&    operator[](unsigned int idx) const;

    /* getter & setter */
    unsigned int size() const;
    /* additional methods */

    /* exception classes */
    class OutofBoundError : public std::exception {
        public:
            const char* what() const throw();
    };
};

#include "Array.tpp"

#endif