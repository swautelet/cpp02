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

	private:
		int	_value;
		static const int _nbit = 8;
};

std::ostream& operator <<(std::ostream& out, const Fixed& nb);

#endif