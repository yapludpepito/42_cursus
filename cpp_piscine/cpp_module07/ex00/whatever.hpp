#ifndef TEMPLATE_FUNCTION_HPP
#define TEMPLATE_FUNCTION_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T d = b; 
    b = a;
    a = d;
}

template <typename T>
T min(T a, T b)
{
    if (a < b)
        return (a);
    else if (a > b)
        return (b);
    else
        return (b);
}

template <typename T>
T max(T a, T b)
{
    if (a > b)
        return (a);
    else if (a < b)
        return (b);
    else
        return (b);
}

#endif