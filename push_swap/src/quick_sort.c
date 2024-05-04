/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsukotarou <komatsukotarou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:32:51 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/05 01:48:40 by komatsukota      ###   ########.fr       */
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
	iter = n ;
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

long	get_pivot_num(char **av)
{
	int		av_count;
	char	**av_dup;

	av_count = 0;
	av_dup = av;
	while (av[av_count])
		av_count++;
	av_count -= 1;
	bubble_sort(av_dup, av_count);
	return (ft_atol(av_dup[av_count / 2 ]));
}

void separated_by_pivot(char **av, t_dst **a, t_dst **b, long pivot_num)
{
	t_dst *a_ptr;
	t_dst *b_ptr;
	int max;
	int i;

	a_ptr = *a;
	b_ptr = *b;
	max = 0;
	i = 0;
	while (av[max])
		max++;
	while (a_ptr->next && i < max)
	{
		if (a_ptr->value <= pivot_num)
		{
			pa(a, b);
			a_ptr = *a;
			i++;
		}
		if (i == max)
			break;
		if (a_ptr->value > pivot_num)
		{
			ra(a);
			a_ptr = *a;
			i++;
		}
	}
	return;
}


/*
return 0; no swap
return 1; swap a
return 2; swap b
return 3; swap a and b
*/
int is_swap(t_dst **a, t_dst **b)
{
	int a_flag;
	int b_flag;
	t_dst	*a_ptr;
	t_dst	*b_ptr;

	a_flag = 0;
	b_flag = 0;
	a_ptr = *a;
	b_ptr = *b;

	if (a_ptr->value > a_ptr->next->value)
		a_flag = 1;
	if (b_ptr->value < b_ptr->next->value)
		b_flag = 1;
	if (a_flag && b_flag)
		return 3;
	else if (a_flag)
		return 1;
	else if (b_flag)
		return 2;
	else
		return 0;
}

/*
return 0; no rotate
return 1; rotate a
return 2; rotate b
return 3; rotate a and b
*/
int is_rotate(t_dst **a, t_dst **b)
{
	int a_flag;
	int b_flag;

	a_flag = 0;
	b_flag = 0;

	if (!is_sorted_ascending(a))
		a_flag = 1;
	if (!is_sorted_descending(b))
		b_flag = 1;
	if (a_flag && b_flag)
		return 3;
	else if (a_flag)
		return 1;
	else if (b_flag)
		return 2;
	else
		return 0;
}

void let_go(t_dst **a, t_dst **b, int is_swap, int is_rotate)
{
	int is_sort_a;
	int is_sort_b;

	if (is_swap == 1)
		sa(a);
	else if (is_swap == 2)
		sb(b);
	else if (is_swap == 3)
		ss(a, b);
	is_sort_a = is_sorted_ascending(a);
	is_sort_b = is_sorted_descending(b);
	if (is_rotate == 1 && !is_sort_a)
		rra(a);
	else if (is_rotate == 2 && !is_sort_b)
		rrb(b);
	else if (is_rotate == 3 && !is_sort_a && !is_sort_b)
		rrr(a, b);
}


int alg_1(t_dst **a, t_dst **b)
{
	while (1)
	{
		let_go(a, b, is_swap(a, b), is_rotate(a, b));
		if (is_sorted_ascending(a) && is_sorted_descending(b))
			break;
		// debug_boxes(a, b);
	}
	return 1;
}

void many_pb(t_dst **a, t_dst **b)
{
	int b_count;
	int i;

	b_count = ft_lstsize(*b);
	i = 0;
	while (i < b_count)
	{
		pb(a, b);
		i++;
	}
	return;
}

// int	main(int ac, char **av)
// {
// 	printf("%ld \n", get_pivot(av));
// 	return (0);
// }
