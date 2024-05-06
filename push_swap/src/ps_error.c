/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:51 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/06 03:50:28 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_int(char *s)
{
	int	i;
	int	max;
	int	zero_count;

	i = 0;
	zero_count = 0;
	max = ft_strlen(s);
	if (max == 1 && (s[i] < '0' || '9' < s[i]))
		return (0);
	while (s[zero_count] == '0')
		zero_count++;
	while (i < max)
	{
		if ((s[0] != '-'))
			if (s[i] < '0' || '9' < s[i])
				return (0);
		if (s[0] == '-' && s[1] == '0')
			return (0);
		i++;
	}
	if (ft_atol(s) < INT_MIN || INT_MAX < ft_atol(s))
		return (0);
	if (zero_count > 1)
		return (0);
	return (1);
}

void	free_char_pp(char **av)
{
	int	max;
	int	i;

	max = count_av(av);
	i = 0;
	while (i < max)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	is_av_error(char **av)
{
	int		i;
	int		j;
	char	**stock;

	i = 0;
	stock = (char **)malloc(sizeof(char *) * count_av(av));
	if (!stock || count_av(av) == 0)
	{
		free(stock);
		return (1);
	}
	while (i < count_av(av))
	{
		stock[i] = NULL;
		if (!is_int(av[i]))
		{
			free(stock);
			return (1);
		}
		j = 0;
		while (stock[j])
		{
			if (ft_strcmp(av[i], stock[j]) == 0)
			{
				free(stock);
				return (1);
			}
			j++;
		}
		stock[i] = av[i];
		i++;
	}
	free(stock);
	return (0);
}

int	output_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
