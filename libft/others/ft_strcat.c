#include "libft.h"

char *strcat(char * restrict dst, const char * restrict src)
{
	size_t i;
	size_t s1_len;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	i = 0;
	while (s2[i] == '\0')
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[i + s1_len] = '\0';
	return s1;
}
