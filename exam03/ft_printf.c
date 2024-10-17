/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:53:26 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/07/12 12:24:11 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	put_str(char *s, int *len)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		*len += write(1, s, 1);
		s++;
	}
}

void	put_number(long long int n, int base, int *len)
{
	char	*s = "0123456789abcdef";
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		*len += write(1, "-", 1);
	}
	if (n >= base)
		put_number((n / base), base, len);
	*len += write(1, &s[n % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	list;

	len = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				put_str(va_arg(list, char *), &len);
			else if (*format == 'd')
				put_number((long long int)va_arg(list, int), 10, &len);
			else if (*format == 'x')
				put_number((long long int)va_arg(list, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(list);
	return (len);
}

int	main(int ac, char **av)
{
	int	len;

	len = ft_printf(av[1], av[2]);
	printf("%d\n", len);
	return (0);
}
