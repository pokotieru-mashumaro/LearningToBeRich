/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:56 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/03 18:33:16 by kkomatsu         ###   ########.fr       */
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
	if (!a)
		return (0);
	b = (t_dst **)malloc(sizeof(t_dst *));
	if (!b)
	{
		free(a);
		return (0);
	}
	init_dst(a, b, ac, av);
	separated_by_pivot(av, a, b, get_pivot_num(av));
	// push_swap(a, b);
	debug_boxes(a, b);
	// printf("%ld\n", ft_atol(av[2]));
	free(a);
	free(b);
	return (0);
}
