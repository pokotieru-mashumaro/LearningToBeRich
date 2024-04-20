/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:24:14 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/16 21:04:06 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(long long now, long long past)
{
	if (now <= 0 && past != 0)
		return (1);
	else
		return (0);
}

long	longmax(int minus)
{
	if (minus == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

void	init(int *i, int *minus, long long *ans, long long *ans_stock)
{
	*i = 0;
	*minus = 1;
	*ans = 0;
	*ans_stock = 0;
}

long 	ft_atol(char *str)
{
	int			i;
	int			minus;
	long long	ans;
	long long	ans_stock;

	init(&i, &minus, &ans, &ans_stock);
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = (ans * 10) + (str[i] - '0');
		i++;
		if (check_overflow(ans, ans_stock))
			return (longmax(minus));
		ans_stock = ans;
	}
	return (minus * ans);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("18446744073709551616"));
// 	printf("%d\n", ft_atoi("18446744073709551616"));
// 	printf("#########\n");
// 	printf("%d\n", atoi("18446744073709551616"));
// 	printf("%d\n", atoi("18446744073709551616"));
// }
