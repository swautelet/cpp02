#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& p);
		const Point& operator =(const Point& p);
		~Point();
		const Fixed& getx();
		const Fixed& gety();

	private:
		const Fixed _x;
		const Fixed _y;

};

#endif