#ifndef ITER_HPP
#define ITER_HPP

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
#define bgGREEN "\033[42m"
#define bgYELLOW "\033[43m"
#define GREY    "\033[38;5;250m"

template <typename T>
void    iter(T* arr, size_t length, void (*f)(T&)) { 
    for (size_t i = 0; i < length; i++) {  f(arr[i]); }
}

template <typename T>
void    iter(const T* arr, size_t length, void (*f)(const T&)) { 
    for (size_t i = 0; i < length; i++) {  f(arr[i]); }
}

/* operators */
#endif