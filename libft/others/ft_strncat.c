#include "libft.h"

char *ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t i;
	size_t s1_len;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	i = 0;
	while (s2[i] == '\0' && i < n)
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[i + s1_len] = '\0';
	return s1;
}
