/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsukotarou <komatsukotarou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:13:46 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/21 01:09:05 by komatsukota      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_dst(t_dst **a, t_dst **b, char **av, t_config *conf)
{
	int	i;
	int	av_count;
	long *arr;

	*a = (t_dst *)malloc(sizeof(t_dst));
	*b = (t_dst *)malloc(sizeof(t_dst));;
	av_count = 0;
	while (av[av_count])
		av_count++;
	av_count--;
	i = 0;
	arr = coordinate_press(av, av_count);
	conf->len = av_count;
	conf->max_num = av_count - 1;
	// printf("^^^^^^^\n");
	*a = NULL;
	*b = NULL;
	while (i < av_count)
	{
		ft_lstadd_back(a, ft_lstnew(arr[i]));
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
	if (*a)
	{
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
	}
	if (*b)
	{
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
	printf("---------------------------\n");
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
