#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(Serializer const &ref)
{
    *this = ref;
}

Serializer &Serializer::operator=(Serializer const &ref)
{
    (void)ref;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t a = reinterpret_cast<uintptr_t>(ptr);
    return (a);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}
