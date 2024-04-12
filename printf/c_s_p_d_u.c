#include "ft_printf.h"

int	c_print(int c)
{
	write(1, &c, 1);
	return (1);
}

int	s_print(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	p_print(unsigned long p)
{
	write(1, "0x", 2);
	return (put_ten2sixteen_long(p) + 2);
}

int	d_i_print(int d)
{
	return (put_nbr(d));
}

int	u_print(unsigned int u)
{
	return (put_unsigned_nbr(u));
}
