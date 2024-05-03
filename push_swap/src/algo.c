/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:13:50 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/03 19:31:12 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
phase_one:
	aの先頭とその次のvalueを比較し、昇順になるようswapする。
	もしaが昇順になっていたらreturnする。
	bにpushする。
	これらをaがなくなるまで行う。

phase_two:
	bの先頭とその次のvalueを比較し、降順になるようswapする。
	もしbが降順になっていたらreturnする。
	aにpushする。
	これらをbがなくなるまで行う。

phase_three

*/

static int	phase_one(t_dst **a, t_dst **b)
{
	t_dst	*a_ptr;

	a_ptr = *a;
	while (a_ptr->next)
	{
		if (a_ptr->value > a_ptr->next->value)
		{
			sa(a);
			a_ptr = *a;
		}
		if (is_sorted_ascending(a) && (!(*b) || !b))
			return (1);
		pa(a, b);
		a_ptr = *a;
	}
	pa(a, b);
	return (0);
}

static int	phase_two(t_dst **a, t_dst **b)
{
	t_dst	*b_ptr;

	b_ptr = *b;
	while (b_ptr->next)
	{
		if (b_ptr->value < b_ptr->next->value)
		{
			sb(b);
			b_ptr = *b;
		}
		pb(a, b);
		b_ptr = *b;
	}
	pb(a, b);
	return (0);
}

static void	phase_three(t_dst **a, t_dst **b)
{
	int	a_flag;
	int	b_flag;

	a_flag = 0;
	b_flag = 0;
	if (!a[0])
		return ;
	if (a[0]->value > ft_lstlast(a)->value)
		a_flag = 1;
	if (!b[0])
		return ;
	if (b[0]->value > ft_lstlast(b)->value)
		b_flag = 1;
	if (a_flag && b_flag)
		rr(a, b);
	return ;
}

void	push_swap(t_dst **a, t_dst **b)
{
	while (1)
	{
		if (phase_one(a, b))
			return ;
		phase_two(a, b);
		// phase_three(a, b);
	}
}
