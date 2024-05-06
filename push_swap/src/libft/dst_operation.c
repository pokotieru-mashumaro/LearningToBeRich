/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:13:54 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/21 18:20:54 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_lstsize(t_dst *dst)
{
	int	count;

	count = 0;
	while (dst)
	{
		dst = dst->next;
		count++;
	}
	return (count);
}

t_dst	*ft_lstlast(t_dst *dst)
{
	if (!dst)
		return (NULL);
	while (dst->next)
		dst = dst->next;
	return (dst);
}

t_dst	*ft_lstnew(long value)
{
	t_dst	*new;

	new = malloc(sizeof(t_dst));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_dst **dst, t_dst *new)
{
	t_dst	*stock;

	if (!(*dst) || !dst)
	{
		*dst = new;
		return ;
	}
	stock = *dst;
	while (stock->next)
		stock = stock->next;
	new->prev = stock;
	stock->next = new;
}

void	ft_lstclear(t_dst **lst)
{
	if (lst && *lst)
	{
		ft_lstclear(&(*lst)->next);
		free(*lst);
		*lst = NULL;
	}
}