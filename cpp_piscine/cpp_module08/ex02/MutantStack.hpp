#include <iostream>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
    public :
        MutantStack() {}
        MutantStack(const MutantStack& target) {*this = target;}
        ~MutantStack() {}
        MutantStack &operator=(MutantStack &target) {(void)target;}

        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::iterator iterator;
        
        const_iterator begin() const
        {
            return (this->c.begin());
        }

        const_iterator end() const
        {
            return (this->c.end());
        }

        iterator begin()
        {
            return (this->c.begin());
        }

        iterator end()
        {
            return (this->c.end());
        }
};