/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsukotarou <komatsukotarou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:56 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/05 02:51:27 by komatsukota      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void skip_zeo(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		av[i] = av[i+1];
		i++;
	}
	return;
}

// void split_av(char **av)
// {
// 	int i;
// 	char **stock;

// 	i = 0;
// 	stock = ft_split(av[1], ' ');
// 	while (av[i])
// 	{
// 		av[i] = NULL;
// 		i++;
// 	}
// 	av = ft_split(stock[1], ' ');
// }

int	main(int ac, char **av)
{
	t_dst	**a;
	t_dst	**b;

	// printf("%ld\n", ft_atol("008"));
	if (ac <= 1)
		return (output_error());
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else if (2 < ac)
		skip_zeo(av);
	if (is_av_error(ac, av))
		return (output_error());
	a = (t_dst **)malloc(sizeof(t_dst *));
	if (!a)
		return (0);
	b = (t_dst **)malloc(sizeof(t_dst *));
	if (!b)
	{
		free(a);
		return (0);
	}
	init_dst(a, b, ac, av);
	// debug_boxes(a, b);
	separated_by_pivot(av, a, b, get_pivot_num(av));
	alg_1(a,b);
	many_pb(a, b);
	// debug_boxes(a, b);
	free(a);
	free(b);
	// exit(1);
	return (0);
}
