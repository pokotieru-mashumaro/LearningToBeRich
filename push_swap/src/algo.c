/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:13:50 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/21 18:28:31 by kkomatsu         ###   ########.fr       */
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
*/

static int	phase_one(t_dst **a, t_dst **b)
{
	t_dst	*a_ptr;

	a_ptr = *a;
	while (a_ptr->next)
	{
		if (a_ptr->value > a_ptr->next->value)
			sa(a);
		if (is_sorted_ascending(a) && (!(*b) || !b))
			return (1);
		pa(a, b);
		a_ptr = a_ptr->next;
	}
	return (0);
}

static int	phase_two(t_dst **a, t_dst **b)
{
	t_dst	*b_ptr;

	b_ptr = *b;
	while (b_ptr->next)
	{
		if (b_ptr->value < b_ptr->next->value)
			sb(b);
		// if (is_sorted_descending(b) && !(b))
		// 	return (1);
		pb(b, a);
		b_ptr = b_ptr->next;
	}
	return (0);
}

void	push_swap(t_dst **a, t_dst **b)
{
	while (1)
	{
		if (phase_one(a, b))
			return ;
		if (phase_two(a, b))
			return ;
	}
}
