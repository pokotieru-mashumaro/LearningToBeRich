/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:25:32 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/21 17:00:29 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_dst **dst)
{
	t_dst	*front;
	t_dst	*bottommost;

	front = *dst;
	bottommost = ft_lstlast(*dst);
	front->prev = bottommost;
	bottommost->next = front;
	bottommost->prev->next = NULL;
	bottommost->prev = NULL;
	*dst = bottommost;
}

void	rra(t_dst **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_dst **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_dst **a, t_dst **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
