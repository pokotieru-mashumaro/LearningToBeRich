#include <stdio.h>

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

int main()
{
    printf("%d\n", find_limit(100));
    return 0;
}