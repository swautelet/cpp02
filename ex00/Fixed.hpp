#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& p);
		int getRawBits() const;
		void setRawBits(int const raw);
		Fixed& operator =(Fixed& p);

	private:
		int	_value;
		static const int _nbit = 8;
};

#endif