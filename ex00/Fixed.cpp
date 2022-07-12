#include"Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed(const Fixed& p)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = p.getRawBits();
}

Fixed& Fixed::operator =(Fixed& p)
{
	if (this != &p)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_value = p.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}