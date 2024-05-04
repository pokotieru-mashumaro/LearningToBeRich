/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:32:51 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/03 20:48:58 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(char **av, int n)
{
	char	*stock;
	int		iter;
	int		onemore;
	int		i;

	stock = 0;
	iter = n ;
	onemore = 0;
	i = 1;
	while (onemore == 0)
	{
		onemore = 1;
		i = 1;
		while (i < iter)
		{
			if (ft_atol(av[i + 1]) < ft_atol(av[i]))
			{
				onemore = 0;
				stock = av[i];
				av[i] = av[i + 1];
				av[i + 1] = stock;
			}
			i++;
		}
	}
}

long	get_pivot_num(char **av)
{
	int		av_count;
	char	**av_dup;

	av_count = 0;
	av_dup = av;
	while (av[av_count])
		av_count++;
	av_count -= 1;
	bubble_sort(av_dup, av_count);	
	return (ft_atol(av_dup[av_count / 2 ]));
}

void separated_by_pivot(char **av, t_dst **a, t_dst **b, long pivot_num)
{
	t_dst *a_ptr;
	t_dst *b_ptr;
	int max;
	int i;

	a_ptr = *a;
	b_ptr = *b;
	max = 0;
	i = 0;
	while (av[max])
		max++;
	max--;
	// printf("%d, %ld\n", max, pivot_num);
	while (a_ptr->next && i < max)
	{
		if (a_ptr->value <= pivot_num)
		{
			pa(a, b);
			a_ptr = *a;
			i++;
		}
		if (a_ptr->value > pivot_num)
		{
			ra(a);
			a_ptr = *a;
			i++;
		}
	}
	return;
}


/*
return 0; no swap
return 1; swap a
return 2; swap b
return 3; swap a and b
*/
int is_swap(t_dst **a, t_dst **b)
{
	int a_flag;
	int b_flag;

	a_flag = 0;
	b_flag = 0;



	if (a_flag && b_flag)
		return 3;
	else if (a_flag)
		return 1;
	else if (b_flag)
		return 2;
	return 0;
}

/*
return 0; no rotate
return 1; rotate a
return 2; rotate b
return 3; rotate a and b
*/
int is_rotate(t_dst **a, t_dst **b)
{
	int a_flag;
	int b_flag;

	a_flag = 0;
	b_flag = 0;

	if (a_flag && b_flag)
		return 3;
	else if (a_flag)
		return 1;
	else if (b_flag)
		return 2;
	return 0;
}


int alg_1()
{

}

// int	main(int ac, char **av)
// {
// 	printf("%ld \n", get_pivot(av));
// 	return (0);
// }
