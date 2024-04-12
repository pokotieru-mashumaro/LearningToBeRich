#include "ft_printf.h"

int	ret_zero(void)
{
	write(1, "0", 1);
	return (1);
}

int	put_ten2sixteen_long(unsigned long n)
{
	char	*base;
	char	ret[32];
	int		i;
	int		count;

	base = "0123456789abcdef";
	i = 0;
	count = 0;
	if (n == 0)
		return (ret_zero());
	while (n > 0)
	{
		ret[i++] = base[n % 16];
		n /= 16;
	}
	while (--i >= 0)
	{
		write(1, &ret[i], 1);
		count++;
	}
	return (count);
}

int	put_ten2sixteen(unsigned int n, int is_upper)
{
	char	*base;
	char	res[32];
	int		i;
	int		count;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (n == 0)
		return (ret_zero());
	count = 0;
	while (n > 0)
	{
		res[i] = base[n % 16];
		n /= 16;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &res[i], 1);
		count++;
	}
	return (count);
}

int	write_and_one(char *res)
{
	write(1, res, 1);
	return (1);
}

int	put_nbr(int n)
{
	long	num;
	char	res[10];
	int		i;
	int		count;

	num = n;
	count = 0;
	if (num == 0)
		return (ret_zero());
	if (num < 0)
	{
		num *= -1;
		count++;
		write(1, "-", 1);
	}
	i = 0;
	while (num > 0)
	{
		res[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	while (--i >= 0)
		count += write_and_one(&res[i]);
	return (count);
}

int	put_unsigned_nbr(unsigned int n)
{
	unsigned long	num;
	char			res[10];
	int				i;
	int				count;

	num = n;
	count = 0;
	if (num == 0)
		return (ret_zero());
	if (num < 0)
	{
		num *= -1;
		count++;
		write(1, "-", 1);
	}
	i = 0;
	while (num > 0)
	{
		res[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	while (--i >= 0)
		count += write_and_one(&res[i]);
	return (count);
}
