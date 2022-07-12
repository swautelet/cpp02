#include"Fixed.hpp"

// constructors

Fixed::Fixed()
{
	this->_value = 0;
	return ;
}

Fixed::Fixed(const int t)
{
	this->_value = t << this->_nbit;
}

Fixed::Fixed(const float t)
{
	this->_value = t * (1 << this->_nbit);
}

Fixed::Fixed(const Fixed& p)
{
	this->_value = p.getRawBits();
}

// operator assine

Fixed& Fixed::operator =(const Fixed& p)
{
	if (this != &p)
	{
		this->_value = p.getRawBits();
	}
	return (*this);
}

// operator compare

bool Fixed::operator >(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator ==(const Fixed& other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator !=(const Fixed& other) const
{
	return (this->_value != other._value);
}

bool Fixed::operator >=(const Fixed& other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator <=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator <(const Fixed& other) const
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
	if (first < second)
		return (first);
	else
		return (second);
	// return(Fixed::min(first, second));
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
	if (first > second)
		return (first);
	else
		return (second);
	// return(Fixed::max(first, second));
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