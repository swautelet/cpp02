#include "Point.hpp"

static bool demi_plan(Point const a, Point const b, Point const c, Point const point)
{
	// std::cout << "demi_plan start" << std::endl;
	if (a.getx() == b.getx())
	{
		if ((c.getx() > a.getx() && point.getx() > a.getx())
			|| (c.getx() < a.getx() && point.getx() < a.getx()))
			return (true);
		else
			return (false);
	}
	Fixed m((a.gety() - b.gety()) / (a.getx() - b.getx()));
	// std::cout << "m calulated successfully " << a.gety() - b.gety() << "/" << a.getx() - b.getx() << "=" << m << std::endl;
	Fixed p(a.gety() - (m * a.getx()));
	// std::cout << "p calulated successfully " << a.gety() << "-" << m << "*" << a.getx() << "=" << p << std::endl;
	if (((m * c.getx()) + p > c.gety() && (m * point.getx()) + p > point.gety())
		|| ((m * c.getx()) + p < c.gety() && (m * point.getx()) + p < point.gety()))
		return (true);
	else
		return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool	droite1 = demi_plan(a, b, c, point);
	// if (droite1)
	// 	std::cout << "droite 1 is true" << std::endl;
	bool	droite2 = demi_plan(b, c, a, point);
	// if (droite2)
	// 	std::cout << "droite 2 is true" << std::endl;
	bool	droite3 = demi_plan(c, a, b, point);
	// if (droite3)
	// 	std::cout << "droite 3 is true" << std::endl;
	if (droite1 && droite2 && droite3)
		return (true);
	else
		return (false);
}