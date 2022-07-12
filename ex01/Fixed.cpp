#include"Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed(const int t)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = t << this->_nbit;
}

Fixed::Fixed(const float t)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = t * (1 << this->_nbit);
}

Fixed::Fixed(const Fixed& p)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = p.getRawBits();
}

Fixed& Fixed::operator =(const Fixed& p)
{
	if (this != &p)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_value = p.getRawBits();
	}
	return (*this);
}

std::ostream& operator <<(std::ostream& out, const Fixed& nb)
{
	out << nb.toFloat();
	return (out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits() const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return(this->_value >> this->_nbit);
}

float Fixed::toFloat(void) const
{
	return((float)this->_value / (1 <<this->_nbit));
}