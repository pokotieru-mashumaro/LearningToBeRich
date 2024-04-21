/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:56 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/21 21:14:12 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_dst	**a;
	t_dst	**b;

	if (ac <= 2)
		return (output_error());
	if (is_av_error(ac, av))
		return (output_error());
	a = (t_dst **)malloc(sizeof(t_dst *));
	b = (t_dst **)malloc(sizeof(t_dst *));
	if (!a || !b)
		return (0);
	init_dst(a, b, ac, av);
	// pa(a, b);
	// pa(a, b);
	sa(a);
	rra(a);
	debug_boxes(a, b);
	printf("END\n");
	return (0);
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
