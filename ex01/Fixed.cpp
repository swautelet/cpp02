#include"Fixed.hpp"

// constructors

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

// operator assine

Fixed& Fixed::operator =(const Fixed& p)
{
	if (this != &p)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_value = p.getRawBits();
	}
	return (*this);
}

// operator compare

bool Fixed::operator >(const Fixed& other)
{
	return (this->_value > other._value);
}

bool Fixed::operator ==(const Fixed& other)
{
	return (this->_value == other._value);
}

bool Fixed::operator !=(const Fixed& other)
{
	return (this->_value != other._value);
}

bool Fixed::operator >=(const Fixed& other)
{
	return (this->_value >= other._value);
}

bool Fixed::operator <=(const Fixed& other)
{
	return (this->_value <= other._value);
}

bool Fixed::operator <(const Fixed& other)
{
	return (this->_value < other._value);
}

// operator arithmetic

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return(result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return(result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() * other.getRawBits());
	return(result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() / other.getRawBits());
	return(result);
}

// operator increment

Fixed& Fixed::operator ++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed& Fixed::operator --()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator ++(int)
{
	Fixed old = *this;
	++(*this);
	return (old);
}

Fixed Fixed::operator --(int)
{
	Fixed old = *this;
	--(*this);
	return (old);
}

// operator ostream

std::ostream& operator <<(std::ostream& out, const Fixed& nb)
{
	out << nb.toFloat();
	return (out);
}

// destructor

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
// min max

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	// if (first < second)
	// 	return (first);
	// else
	// 	return (second);
	return(Fixed::min(first, second));
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	// if (first > second)
	// 	return (first);
	// else
	// 	return (second);
	return(Fixed::max(first, second));
}

// core function

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