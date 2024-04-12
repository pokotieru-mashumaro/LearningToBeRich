#include "ft_printf.h"

int	percent_terminal(const char branch_char, void *args)
{
	if (branch_char == 's')
		return (s_print((char *)args));
	else if (branch_char == 'p')
		return (p_print((unsigned long)args));
	return (0);
}

int	percent_terminal2(const char branch_char, int args)
{
	if (branch_char == 'c')
		return (c_print((int)args));
	else if (branch_char == 'd' || branch_char == 'i')
		return (d_i_print((int)args));
	else if (branch_char == 'u')
		return (u_print((unsigned int)args));
	else if (branch_char == 'x')
		return (x_print((unsigned int)args));
	else if (branch_char == 'X')
		return (upper_x_print((unsigned int)args));
	else if (branch_char == '%')
		return (per_print());
	return (0);
}

int	memsize_switch(char c)
{
	if (c == 's' || c == 'p')
		return (8);
	else
		return (4);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == 's' || *format == 'p')
				count += percent_terminal(*format, va_arg(args, void *));
			else
				count += percent_terminal2(*format, va_arg(args, int));
		}
		format++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	b;
// 	int	c;

// 	b = ft_printf("%d %d %%\n", 42, -2147483648);
// 	c = printf("%d %ld %%\n", 42, -2147483648);
// 	printf("ft = %d | natural = %d", b, c);
// 	return (0);
// }
