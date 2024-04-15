#include "ft_printf.h"

int	percent_terminal(const char branch_char, va_list *args)
{
	if (branch_char == 's')
		return (s_print(va_arg(*args, char *)));
	else if (branch_char == 'p')
		return (p_print(va_arg(*args, unsigned long)));
		else if (branch_char == 'c')
		return (c_print(va_arg(*args, int)));
	else if (branch_char == 'd' || branch_char == 'i')
		return (d_i_print(va_arg(*args, int)));
	else if (branch_char == 'u')
		return (u_print(va_arg(*args, unsigned int)));
	else if (branch_char == 'x')
		return (x_print((va_arg(*args, unsigned int))));
	else if (branch_char == 'X')
		return (upper_x_print(va_arg(*args, unsigned int)));
	else if (branch_char == '%')
		return (per_print());
	return (0);
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
			count += percent_terminal(*format, &args);
		}
		format++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	b;
	int	c;

	int d = 42;
	char *e= "aaa";
	b = ft_printf("%d %p %%\n", d, e);
	c = printf("%d %p %%\n", d, e);
	printf("ft = %d | natural = %d", b, c);
	return (0);
}
