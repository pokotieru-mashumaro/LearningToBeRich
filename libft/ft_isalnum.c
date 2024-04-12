#include "libft.h"

int ft_isalnum(int c)
{
	if (48 <= c && c <= 57)
		return 1;
	if (65 <= c && c <= 90)
		return 1;
	if (97 <= c && c <= 122)
		return 1;
	return 0;
}
