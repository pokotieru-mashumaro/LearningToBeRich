/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:56 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/06 03:53:56 by kkomatsu         ###   ########.fr       */
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

int	under_five_av_checker(t_dst **a, t_dst **b, char **av)
{
	if (count_av(av) == 2)
	{
		sa(a);
		return (1);
	}
	if (count_av(av) == 3)
	{
		three_arg(av, a, b);
		return (1);
	}
	if (count_av(av) > 6)
	{
		push_swap(a, b);
		return (1);
	}
	return (0);
}

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

int	main(int ac, char **av)
{
	t_dst	**a;
	t_dst	**b;

	if (ac <= 2)
		return (output_error());
	skip_zeo(av);
	if (is_av_error(av))
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
	init_dst(a, b, av);
	if (is_sorted_ascending(a))
	{
		ft_lstclear(a);
		ft_lstclear(b);
		return (0);
	}
	if (under_five_av_checker(a, b, av))
		return (0);
	separated_by_pivot(av, a, b, get_pivot_num(av));
	alg_1(a, b);
	many_pb(a, b);
	ft_lstclear(a);
	ft_lstclear(b);
	return (0);
}
