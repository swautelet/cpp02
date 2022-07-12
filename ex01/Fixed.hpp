#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>

class Fixed{
	public:
		Fixed();
		Fixed(const int t);
		Fixed(const float t);
		~Fixed();
		Fixed(const Fixed& p);
		float toFloat(void) const;
		int	toInt(void) const;
		int getRawBits() const;
		void setRawBits(int const raw);
		Fixed& operator =(const Fixed& p);
		bool operator >(const Fixed& other);
		bool operator <(const Fixed& other);
		bool operator ==(const Fixed& other);
		bool operator !=(const Fixed& other);
		bool operator >=(const Fixed& other);
		bool operator <=(const Fixed& other);
		Fixed& operator +(const Fixed& other);
		Fixed& operator -(const Fixed& other);
		Fixed& operator *(const Fixed& other);
		Fixed& operator /(const Fixed& other);
		Fixed& operator ++();
		Fixed& operator --();
		Fixed operator ++(int other);
		Fixed operator --(int other);
		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);

	private:
		int	_value;
		static const int _nbit = 8;
};

std::ostream& operator <<(std::ostream& out, const Fixed& nb);

#endif