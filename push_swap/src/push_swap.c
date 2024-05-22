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

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}

int	count_av(char **av)
{
	int	av_count;

	av_count = 0;
	while (av[av_count])
		av_count++;
	return (av_count);
}

void	many_pb(t_dst **a, t_dst **b)
{
	int	b_count;
	int	i;

	b_count = ft_lstsize(*b);
	i = 0;
	while (i < b_count)
	{
		pa(a, b);
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
	if (conf->len > 10)
	{
		radix_sort(a, b, conf);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_dst	**a;
	t_dst	**b;
	t_config * conf;

	if (ac <= 2)
		return (output_error());
	if (is_av_error(av))
		return (output_error());
	a = (t_dst **)malloc(sizeof(t_dst *));
	b = (t_dst **)malloc(sizeof(t_dst *));
	conf = (t_config *)malloc(sizeof(t_config));
	if (!a || !b || !conf)
		exit(0);
	init_dst(a, b, av, conf);
	if (is_sorted_ascending(a))
		exit(0);
	if (under_five_av_checker(a, b, av, conf))
		exit(0);
	separated_by_pivot(av, a, b, get_pivot_num(av));
	alg_1(a, b);
	many_pb(a, b);
	exit(0);
	return (0);
}
