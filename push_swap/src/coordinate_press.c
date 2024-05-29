/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:46:09 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/22 18:25:04 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	partition(long *arr, int low, int high)
{
	long	pivot;
	int		i;
	int		j;
	long	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

static void	quicksort(long *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quicksort(arr, low, pivot_index - 1);
		quicksort(arr, pivot_index + 1, high);
	}
}

static long	*sort(char **av, int len)
{
	int		i;
	long	*arr;

	arr = (long *)malloc(len * sizeof(long));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = atol(av[i]);
		i++;
	}
	quicksort(arr, 0, len - 1);
	return (arr);
}

long	*coordinate_press(char **av, int len)
{
	long	*ret;
	long	*arr;
	int		i;
	int		j;

	av++;
	arr = sort(av, len);
	ret = (long *)malloc(len * sizeof(long));
	if (!ret || !arr)
		exit(0);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (ft_atol(av[i]) == arr[j])
			{
				ret[i] = j;
				break ;
			}
		}
	}
	free(arr);
	return (ret);
}

// int main(void) {
//     char *input[] = { "3", "2", "1"};
//     int len = sizeof(input) / sizeof(input[0]);

//     long* sorted = sort(input, len);

//     for (int i = 0; i < len; i++) {
//         printf("%ld\n", sorted[i]);
//     }
//     free(sorted);

//     return (0);
// }
