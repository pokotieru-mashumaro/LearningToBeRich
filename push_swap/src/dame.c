/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dame.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:32:51 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/28 17:14:31 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_arg(t_dst **a, t_dst **b)
{
	long	top;
	long	middle;

	top = (*a)->value;
	middle = (*a)->next->value;

	//132 213 231 312 321
	if (top == 0 && middle == 2)
	{
		pb(a, b);
		sa(a);
		pa(a, b);
	}
	else if (top == 1 && middle == 0)
		sa(a);
	else if (top == 1 && middle == 2)
		rra(a);
	else if (top == 2 && middle == 0)
		ra(a);
	else if (top == 2 && middle == 1)
	{
		ra(a);
		sa(a);
	}
	return ;
}

/*
return (0); no swap
return (1); swap a
return (2); swap b
return (3); swap a and b
*/
static int	is_swap(t_dst **a, t_dst **b)
{
	int		a_flag;
	int		b_flag;
	t_dst	*a_ptr;
	t_dst	*b_ptr;

	a_flag = 0;
	b_flag = 0;
	a_ptr = *a;
	b_ptr = *b;
	if (a_ptr->value > a_ptr->next->value && a_ptr != NULL
		&& a_ptr->next != NULL)
		a_flag = 1;
	if (!(!(b_ptr->next)))
		if (b_ptr->value < b_ptr->next->value && b_ptr != NULL
			&& b_ptr->next != NULL)
			b_flag = 1;
	if (a_flag && b_flag)
		return (3);
	else if (a_flag)
		return (1);
	else if (b_flag)
		return (2);
	else
		return (0);
}

/*
return (0); no rotate
return (1); rotate a
return (2); rotate b
return (3); rotate a and b
*/
static int	is_rotate(t_dst **a, t_dst **b)
{
	int	a_flag;
	int	b_flag;

	a_flag = 0;
	b_flag = 0;
	if (!is_sorted_ascending(a))
		a_flag = 1;
	if (!is_sorted_descending(b))
		b_flag = 1;
	if (a_flag && b_flag)
		return (3);
	else if (a_flag)
		return (1);
	else if (b_flag)
		return (2);
	else
		return (0);
}

static void	let_go(t_dst **a, t_dst **b, int is_swap, int is_rotate)
{
	int	is_sort_a;
	int	is_sort_b;

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

int	alg_1(t_dst **a, t_dst **b)
{
	while (1)
	{
		let_go(a, b, is_swap(a, b), is_rotate(a, b));
		if (is_sorted_ascending(a) && is_sorted_descending(b))
			break ;
	}
	return (1);
}

// int	main(int ac, char **av)
// {
// 	printf("%ld \n", get_pivot(av));
// 	return (0);
// }
