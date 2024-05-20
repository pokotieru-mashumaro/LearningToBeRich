/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsukotarou <komatsukotarou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:24:14 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/20 22:44:07 by komatsukota      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_overflow(long long now, long long past)
{
	if (now <= 0 && past != 0)
		return (1);
	else
		return (0);
}

static long	longmax(int minus)
{
	if (minus == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

static void	init(int *i, int *minus, long long *ans, long long *ans_stock)
{
	*i = 0;
	*minus = 1;
	*ans = 0;
	*ans_stock = 0;
}

long	ft_atol(char *str)
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
// 	printf("%ld\n", ft_atol("12"));
// 	printf("%ld\n", ft_atol("18446744073709551616"));
// }
