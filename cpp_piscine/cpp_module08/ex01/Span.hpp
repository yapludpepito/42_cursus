#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

class span
{
    private :
        unsigned int size;
        unsigned int index;
        std::vector<int> a;
    public :
        span();
        span(unsigned int n);
        span *operator=(const span &ref);
        void    addNumber(int number);
        int     shortestSpan();
        int     longestSpan();
        void    addManyNumbers(int *, int);
        ~span();
};


#endif