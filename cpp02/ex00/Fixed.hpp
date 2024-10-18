#ifndef   Fixed_HPP
#define   Fixed_HPP

#include <iostream>

class Fixed {
private:
	int _fixed_point_number;
	static const int _static_constant_integer = 8;
public:
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed&	operator=(const Fixed &copy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif
