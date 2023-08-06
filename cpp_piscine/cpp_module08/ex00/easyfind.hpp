#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template <class T>
typename T::const_iterator   easyfind(T to_check, int nb)
{
    typename T::const_iterator result = std::find(to_check.begin(), to_check.end(), nb);
    if (to_check.end() == result)
        throw std::out_of_range("result not found\n");
    return (result);
}

#endif