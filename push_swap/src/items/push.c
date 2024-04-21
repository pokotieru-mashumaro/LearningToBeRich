/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:23:35 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/21 18:51:18 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_dst **send, t_dst **recieve)
{
	t_dst	*send_to_recieve;
	t_dst	*recieve_ptr;

	send_to_recieve = *send;
	recieve_ptr = *recieve;
	*send = send_to_recieve->next;
	send_to_recieve->next->prev = NULL;
	send_to_recieve->next = recieve_ptr;
	recieve_ptr->prev = send_to_recieve;
	*recieve = send_to_recieve;
}

void	pa(t_dst **a, t_dst **b)
{
	if (!(*a) || !a)
		return ;
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_dst **a, t_dst **b)
{
	if (!(*b) || !b)
		return ;
	push(b, a);
	write(1, "pb\n", 3);
}
