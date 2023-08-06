#include "Point.hpp"

int main( void )
{
	Point a(0.0f, 0.0f);
	Point b(6.0f, 8.5f);
	Point c(12.0f, 0.0f);
	Point p(4.5f, 4.0f);
	Point d(.0f, .0f);

	d = p;

	bool i = bsp(a, b, c, p);
	if (i == true)
		std::cout << "he is in \n";
	else
		std::cout << "he is out \n";
	return 0;
}