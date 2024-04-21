/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:24:25 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/21 17:00:33 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_dst **dst)
{
	t_dst	*front;
	t_dst	*back;

	front = *dst;
	back = front->next;
	front->next = NULL;
	back->prev = NULL;
	*dst = back;
	ft_lstadd_back(dst, front);
}

void	ra(t_dst **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_dst **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_dst **a, t_dst **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
