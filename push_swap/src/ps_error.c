/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:51 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/28 19:45:39 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

static int	is_int(char *s)
{
	int	i;
	int	max;
	int	zero_count;

	i = 0;
	zero_count = 0;
	max = ft_strlen(s);
	if (max == 1 && !ft_isdigit(s[i]))
		return (0);
	while (s[zero_count] == '0')
		zero_count++;
	while (i < max)
	{
		if (s[0] != '-' && !ft_isdigit(s[i]))
			return (0);
		if (i != 0 && !ft_isdigit(s[i]))
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

void	error_component(char **stk, char **av, int i)
{
	int	j;

	j = 1;
	while (stk[j])
	{
		if (ft_strcmp(av[i], stk[j]) == 0)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		j++;
	}
	stk[i] = av[i];
}

int	is_av_error(char **av)
{
	int		i;
	char	**stock;

	i = 1;
	stock = (char **)malloc(sizeof(char *) * count_av(av));
	if (!stock || count_av(av) == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	while (i < count_av(av))
	{
		stock[i] = NULL;
		if (!is_int(av[i]))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		error_component(stock, av, i);
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
