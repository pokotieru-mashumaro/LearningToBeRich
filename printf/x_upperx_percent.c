#include "ft_printf.h"

int	x_print(unsigned int x)
{
	return (put_ten2sixteen(x, 0));
}

int	upper_x_print(unsigned int x)
{
	return (put_ten2sixteen(x, 1));
}

int	per_print(void)
{
	write(1, "%", 1);
	return (1);
}
