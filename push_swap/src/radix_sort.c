#include "../includes/push_swap.h"

// https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
//箱が2つなのでビット演算を用いる

static long	get_top(t_dst *dst)
{
	return (dst->value);
}

void	radix_sort(t_dst **a, t_dst **b, t_config *conf)
{
	int	max_bits;
	int	i;
	int	j;
	long	num;

	max_bits = 0;
	while ((conf->max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits && !is_sorted_ascending(a))
	{
		j = 0;
		while (j < conf->len)
		{
			num = get_top(*a);
			if (num & (1<<i))
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

int main(int ac, char **av)
{
	t_dst	**a;
	t_dst	**b;
	t_config * conf;

	a = (t_dst **)malloc(sizeof(t_dst *));
	if (!a)
		return (0);
	b = (t_dst **)malloc(sizeof(t_dst *));
	if (!b)
	{
		free(a);
		return (0);
	}
	conf = (t_config *)malloc(sizeof(t_config));
	init_dst(a, b, av, conf);
	radix_sort(a, b, conf);
	return 0;
}
