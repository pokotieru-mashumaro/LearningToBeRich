#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	unsigned char *ptr_s;

	i = 0;
	ptr_s = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr_s == (unsigned char) c)
			return (ptr_s);
		ptr_s++;
		i++;
	}
	return NULL;
}

