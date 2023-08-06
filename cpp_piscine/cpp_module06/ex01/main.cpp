#include "Serializer.hpp"

//reinterpret cast

int main(void)
{
    Data *ptr = new Data();
    Data *ptr0;

    ptr->i = 2334;
    uintptr_t a = Serializer::serialize(ptr);
    ptr0 = Serializer::deserialize(a);
    std::cout << ptr->i << std::endl;
    std::cout << ptr0->i << std::endl;
    std::cout << &ptr << std::endl;
    std::cout << &ptr0 << std::endl;
    delete ptr;
}