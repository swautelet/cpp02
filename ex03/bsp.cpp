#include "Point.hpp"

static bool demi_plan(Point const a, Point const b, Point const c, Point const point)
{
	Fixed m((a.gety() - b.gety()) / (a.getx() - b.getx()));
	Fixed p(a.gety() - (m * a.getx()));
	if (((m * c.getx()) + p - c.gety() > 0 && (m * point.getx()) + p - point.gety() > 0)
		|| ((m * c.getx()) + p - c.gety() < 0 && (m * point.getx()) + p - point.gety() < 0))
		return (true);
	else
		return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool	droite1 = demi_plan(a, b, c, point);
	bool	droite2 = demi_plan(b, c, a, point);
	bool	droite3 = demi_plan(c, a, b, point);
	if (droite1 && droite2 && droite3)
		return (true);
	else
		return (false);
}