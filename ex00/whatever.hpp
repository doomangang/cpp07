#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

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

template<typename T>
void    swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
const T& min(const T& a, const T& b) {
    return ( a < b ) ? a : b;
}

template<typename T>
T& min(T& a, T& b) {
    return ( a < b ) ? a : b;
}

template<typename T>
const T& max(const T& a, const T& b) {
    return ( a > b ) ? a : b;
}

template<typename T>
T& max(T& a, T& b) {
    return ( a > b ) ? a : b;
}

/* operators */
#endif