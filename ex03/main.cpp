#include"Point.hpp"

int main()
{
	Point a(4, 10);
	Point b(4, 6);
	Point c(10, 6);
	Point point(4.1, 6.1);

	if (bsp(a, b, c, point))
		std::cout << "point is in the triangle." << std::endl;
	else
		std::cout << "Point is not in the triangle." << std::endl;
}