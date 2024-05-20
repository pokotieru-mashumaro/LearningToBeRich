/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsukotarou <komatsukotarou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:48:09 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/20 23:32:51 by komatsukota      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	bubble_sort(char **av, int n)
{
	char	*stock;
	int		iter;
	int		onemore;
	int		i;

	stock = 0;
	iter = n;
	onemore = 0;
	i = 1;
	while (onemore == 0)
	{
		onemore = 1;
		i = 1;
		while (i < iter)
		{
			if (ft_atol(av[i + 1]) < ft_atol(av[i]))
			{
				onemore = 0;
				stock = av[i];
				av[i] = av[i + 1];
				av[i + 1] = stock;
			}
			i++;
		}
	}
}
