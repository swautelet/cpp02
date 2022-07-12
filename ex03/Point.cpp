#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
	return ;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	return ;
}

Point::Point(const Point& p): _x(p._x), _y(p._y)
{
	return ;
}

const Fixed& Point::getx() const
{
	return(this->_x);
}

const Fixed& Point::gety() const
{
	return(this->_y);
}

const Point& Point::operator =(const Point& p)
{
	// Point result(p);
	return (p);
}

Point::~Point()
{
	return ;
}