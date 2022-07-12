#include"Point.hpp"

int main()
{
	Point a(4, 10.1);
	Point b(4.1, 6);
	Point c(10, 6.1);
	Point point(20, 20);

	if (bsp(a, b, c, point))
		std::cout << "point is in the triangle." << std::endl;
	else
		std::cout << "Point is not in the triangle." << std::endl;
}