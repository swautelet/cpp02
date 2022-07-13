#include"Point.hpp"

int main()
{
	Point a(4, 10);
	Point b(4, 6);
	Point c(10, 6);
	Point point(4.1, 6.1);

	std::cout << "The 3 corners of the triangle are a:" << a.getx() << "," << a.gety();
	std::cout << "	b:" << b.getx() << "," << b.gety();
	std::cout << "	c:" << c.getx() << "," << c.gety() << std::endl;
	std::cout << "The point searched is :" << point.getx() << "," << point.gety() << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "point is in the triangle." << std::endl;
	else
		std::cout << "Point is not in the triangle." << std::endl;
}