/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:23:35 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/24 23:49:49 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_dst **send, t_dst **recieve)
{
	t_dst	*send_to_recieve;
	t_dst	*next_send_top;
	t_dst	*recieve_ptr;

	send_to_recieve = *send;
	next_send_top = send_to_recieve->next;
	recieve_ptr = *recieve;
	send_to_recieve->next = recieve_ptr;
	if (next_send_top)
		next_send_top->prev = NULL;
	if (!(!recieve || !(*recieve)))
		recieve_ptr->prev = send_to_recieve;
	*send = next_send_top;
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
