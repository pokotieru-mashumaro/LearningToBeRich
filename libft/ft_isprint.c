#include "libft.h"

int ft_isprint(int c)
{
	if (c < 32 || 126 < c)
		return 0;
	return 1;
}
