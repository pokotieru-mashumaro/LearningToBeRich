#ifndef   Fixed_HPP
#define   Fixed_HPP

#include <iostream>

class Fixed {
private:
	int _fixed_point_number;
	static const int _fractional_bits = 8;
public:
	Fixed(void);
    Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &copy);
	Fixed&	operator=(const Fixed &copy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream & operator<<(std::ostream &o, Fixed const &i);

#endif
