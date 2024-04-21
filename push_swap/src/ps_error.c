/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:51 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/21 21:10:18 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_int(char *s)
{
	int	i;
	int	max;

	i = 0;
	max = ft_strlen(s);
	if (max == 1 && (s[i] < '0' || '9' < s[i]))
		return (0);
	while (i < max)
	{
		if ((s[0] != '-'))
			if (s[i] < '0' || '9' < s[i])
				return (0);
		i++;
	}
	if (ft_atol(s) < INT_MIN || INT_MAX < ft_atol(s))
		return (0);
	return (1);
}

int	is_av_error(int ac, char **av)
{
	int		i;
	int		j;
	char	**stock;

	i = 1;
	stock = (char **)malloc(ac * sizeof(char *));
	if (!stock)
		return (1);
	while (i < ac)
	{
		stock[i - 1] = NULL;
		if (!is_int(av[i]))
			return (1);
		j = 0;
		while (stock[j])
		{
			if (ft_strcmp(av[i], stock[j]) == 0)
				return (1);
			j++;
		}
		stock[i - 1] = av[i];
		i++;
	}
	stock[i - 1] = NULL;
	return (0);
}

int	output_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
