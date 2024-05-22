/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separated_by_pivot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:36:57 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/05 16:37:00 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	get_pivot_num(char **av)
{
	int		av_count;
	char	**av_dup;

	av_dup = av;
	av_count = count_av(av);
	av_count -= 1;
	bubble_sort(av_dup, av_count);
	return (ft_atol(av_dup[av_count / 2]));
}

void	separated_by_pivot(char **av, t_dst **a, t_dst **b, long pivot_num)
{
	t_dst	*a_ptr;
	int		max;
	int		i;

	a_ptr = *a;
	i = 0;
	max = count_av(av) - 1;
	while (a_ptr->next && i < max)
	{
		if (a_ptr->value <= pivot_num)
		{
			pb(a, b);
			a_ptr = *a;
			i++;
		}
		if (a_ptr->value > pivot_num && i != max)
		{
			ra(a);
			a_ptr = *a;
			i++;
		}
	}
	return ;
}
