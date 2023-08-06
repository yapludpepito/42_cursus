#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    print(T a)
{
    std::cout << a << std::endl;
}

template <typename T>
void     iter(T *Array, int len, void (*function)(T))
{
    for (int i = 0; i < len; i++)
    {
        function(Array[i]);
    }
}



#endif