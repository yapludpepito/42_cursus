#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    public :
        class out_of_range : public std::exception {
            public :
                const char *what(void) const throw()
                {
                    return ("Out of range\n");
                }
        };
        
        Array<T>()
        {
            this->_size = 0;
            this->a = new T[_size]();
        }

        Array<T>(unsigned int n)
        {
            this->_size = n;
            this->a = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                a[i] = 0;
        }

        Array<T>(Array &ref)
        {
            this->_size = ref._size;
            this->a = new T[_size]();
            if (this != &ref && ref._size != 0)
            {
                for (unsigned int i = 0; i < ref._size; i++)
                {
                    this->a[i] = ref.a[i];
                }
            }
        }

        Array<T> *operator=(const Array<T> &ref)
        {
            if (this != &ref && ref._size != 0)
            {
                this->a = new T[this->_size]();
                for (unsigned int i = 0; i < ref._size; i++)
                {
                    this->a[i] = ref.a[i];
                }
                return (this);
            }
            else
                return (NULL);
        }

        T &operator[](const int index) const
        {
            if (this->_size <= (const unsigned int)index || index < 0)
                throw (out_of_range());
            return (a[index]);
        }

        unsigned int size()
        {
            return (this->_size);
        }

        ~Array<T>()
        {
            delete []a;
        }

    private :
        unsigned int _size;
        T *a;
};




#endif