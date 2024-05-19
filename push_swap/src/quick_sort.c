#include "../includes/push_swap.h"

int	find_limit(int len)
{
	int	limit;

	limit = 0;
	while ((len / 2) != 0)
	{
		limit++;
		len = len / 2;
	}
	return (limit);
}

int	all_quick(t_dst **a, t_dst **b)
{
    int size;

    size = find_limit(ft_lstsize(a));
    while (size >= 0)
    {

        size--;
    }
    

}