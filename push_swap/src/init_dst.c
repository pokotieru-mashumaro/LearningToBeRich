/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:13:46 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/21 20:40:35 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_dst(t_dst **a, t_dst **b, int ac, char **av)
{
	int	i;

	*a = NULL;
	*b = NULL;
	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atol(av[i])));
		i++;
	}
}

int	is_sorted_ascending(t_dst **a)
{
	t_dst	*stock;
	long	judge;

	stock = *a;
	judge = stock->value;
	while (stock->next)
	{
		stock = stock->next;
		if (judge > stock->value)
			return (0);
		judge = stock->value;
	}
	return (1);
}

int	is_sorted_descending(t_dst **b)
{
	t_dst	*stock;
	long	judge;

	stock = *b;
	judge = stock->value;
	while (stock->next)
	{
		stock = stock->next;
		if (judge < stock->value)
			return (0);
		judge = stock->value;
	}
	return (1);
}

void	debug_boxes(t_dst **a, t_dst **b)
{
	int		i;
	t_dst	*stock;

	printf("DEBUG start!!\n");
	i = 0;
	stock = *a;
	while (stock->next)
	{
		printf("a: %d番目  =  %ld\n", i + 1, stock->value);
		stock = stock->next;
		i++;
	}
	printf("a: %d番目  =  %ld\n\n", i + 1, stock->value);
	if (!b || !(*b))
		return ;
	i = 0;
	stock = *b;
	while (stock->next)
	{
		printf("b: %d番目  =  %ld\n", i + 1, stock->value);
		stock = stock->next;
		i++;
	}
	printf("b: %d番目  =  %ld\n", i + 1, stock->value);
}

// int	main(int ac, char **av)
// {
// 	t_dst	**a;
// 	t_dst	**b;

// 	a = (t_dst **)malloc(sizeof(t_dst));
// 	b = (t_dst **)malloc(sizeof(t_dst));
// 	init_dst(a, b, ac, av);
// 	// reverse_rotate(a);
// 	debug_boxes(a, b);
// 	printf("is sorted: %d\n", is_sorted_descending(a));
// 	return (0);
// }
