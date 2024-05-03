/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:32:51 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/03 20:48:58 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(char **av, int n)
{
	char	*stock;
	int		iter;
	int		onemore;
	int		i;

	stock = 0;
	iter = n - 1;
	onemore = 0;
	i = 0;
	while (onemore == 0)
	{
		onemore = 1;
		i = 0;
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

long	get_pivot(char **av)
{
	int		av_count;
	int		pivot_num;
	char	**av_dup;

	av_count = 0;
	av_dup = av;
	while (av[av_count])
		av_count++;
	av_count -= 1;
	printf("%d \n", av_count);
	bubble_sort(av_dup, av_count);
	if (av_count % 2 == 1)
		return (ft_atol(av_dup[av_count / 2 + 1]));
	else
	{
		return (ft_atol(av_dup[av_count / 2 + 1]));
	}
}

int	main(int ac, char **av)
{
	printf("%d \n", get_pivot(av));
	return (0);
}
