/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsukotarou <komatsukotarou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:56 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/21 01:27:16 by komatsukota      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_av(char **av)
{
	int	av_count;

	av_count = 0;
	while (av[av_count])
		av_count++;
	return (av_count);
}

void	skip_zeo(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = av[i + 1];
		i++;
	}
	return ;
}

void	many_pb(t_dst **a, t_dst **b)
{
	int	b_count;
	int	i;

	b_count = ft_lstsize(*b);
	i = 0;
	while (i < b_count)
	{
		pb(a, b);
		i++;
	}
	return ;
}

int	under_five_av_checker(t_dst **a, t_dst **b, char **av, t_config *conf)
{
	if (conf->len == 2)
	{
		sa(a);
		return (1);
	}
	if (conf->len == 3)
	{
		three_arg(av, a, b);
		return (1);
	}
	if (conf->len > 6)
	{
		radix_sort(a, b, conf);
		return (1);
	}
	return (0);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int	main(int ac, char **av)
// {
// 	t_dst	**a;
// 	t_dst	**b;
// 	t_config * conf;

// 	if (ac <= 2)
// 		return (output_error());
// 	skip_zeo(av);
// 	if (is_av_error(av))
// 		return (output_error());
// 	a = (t_dst **)malloc(sizeof(t_dst *));
// 	if (!a)
// 		return (0);
// 	b = (t_dst **)malloc(sizeof(t_dst *));
// 	if (!b)
// 	{
// 		free(a);
// 		return (0);
// 	}
// 	conf = (t_config *)malloc(sizeof(t_config));
// 	init_dst(a, b, av, conf);
// 	if (is_sorted_ascending(a))
// 	{
// 		ft_lstclear(a);
// 		ft_lstclear(b);
// 		return (0);
// 	}
// 	if (under_five_av_checker(a, b, av, conf))
// 		return (0);
// 	separated_by_pivot(av, a, b, get_pivot_num(av));
// 	alg_1(a, b);
// 	many_pb(a, b);
// 	ft_lstclear(a);
// 	ft_lstclear(b);
// 	return (0);
// }
