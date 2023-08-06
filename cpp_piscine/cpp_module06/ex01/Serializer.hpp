#ifndef SERIALZER_HPP
#define SERIALZER_HPP

#include <iostream>
#include <stdint.h>
#include "data.h"


class Serializer
{
    private :
        Serializer();
        ~Serializer();
        Serializer(Serializer const &ref);

    public :
        Serializer &operator=(Serializer const &ref);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};



#endif