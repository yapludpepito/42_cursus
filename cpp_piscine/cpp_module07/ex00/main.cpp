#include "whatever.hpp"

int main(void)
{
    int a = 5;
    int b = 10;
    char c = 'a';
    char d = 'b';

    std::cout << "first print\n";
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    swap(a, b);
    std::cout << "second print\n";
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "third print\n";
    std::cout << min(a, b) << std::endl;
    std::cout << max(a, b) << std::endl;
    std::cout << "fourth print\n";
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    swap(c, d);
    std::cout << "fifth print\n";
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << "sixth print\n";
    std::cout << min(c,d) << std::endl;
    std::cout << max(c,d) << std::endl;
}

// int main( void ) {
// int a = 2;
// int b = 3;
// ::swap( a, b );
// std::cout << "a = " << a << ", b = " << b << std::endl;
// std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// std::string c = "chaine1";
// std::string d = "chaine2";
// ::swap(c, d);
// std::cout << "c = " << c << ", d = " << d << std::endl;
// std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// return 0;
// }
