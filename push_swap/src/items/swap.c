/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:22:05 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/24 23:49:30 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_dst **dst)
{
	t_dst	*front_to_back;
	t_dst	*back_to_front;
	t_dst	*theard_num;

	front_to_back = *dst;
	back_to_front = front_to_back->next;
	if (!front_to_back || !back_to_front)
		return ;
	theard_num = back_to_front->next;
	front_to_back->next = theard_num;
	front_to_back->prev = back_to_front;
	back_to_front->next = front_to_back;
	back_to_front->prev = NULL;
	if (theard_num)
		theard_num->prev = front_to_back;
	*dst = back_to_front;
}

void	sa(t_dst **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_dst **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_dst **a, t_dst **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
