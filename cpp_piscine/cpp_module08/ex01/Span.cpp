#include "Span.hpp"

span::span()
{
    size = 2;
    index = 0;
}

span::span(unsigned int n)
{
    size = n;
    index = 0;
}

span *span::operator=(const span &ref)
{
    if (this != &ref)
    {
        this->size = ref.size;
        for (unsigned int i = 0; i < ref.index; i++)
            this->a.at(i) = ref.a.at(i);
        a.resize(size);
        return (this);
    }
    else
        return (this);
}

void    span::addNumber(int number)
{
    if (index == size)
        throw std::out_of_range("out of range\n");
    else
    {
        a.push_back(number);
        index++;
    }

}
int     span::shortestSpan()
{
    if (index <= 1)
        throw std::out_of_range("out of range\n");
    int span = 2147483647;
    std::sort(a.begin(), a.end());
    for (unsigned int j = 0; j < index - 1; j++)
    {
        if (abs(a.at(j) - a.at(j + 1)) < span)
            span = abs(a.at(j) - a.at(j + 1));
    }
    return (span);
}

int     span::longestSpan()
{
    if (index <= 1)
        throw std::out_of_range("out of range\n");
    std::vector<int>::iterator min = std::min_element(a.begin(), a.end());
    std::vector<int>::iterator max = std::max_element(a.begin(), a.end());
    return (abs(*max - *min));
}

void    span::addManyNumbers(int *tab, int size)
{
    if (this->index + size > this->size)
        throw std::out_of_range("out of range\n");
    this->a.insert(a.end(), tab, tab + size);   
    index += size;
}

span::~span() {}