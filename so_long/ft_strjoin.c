#include "so_long.h"

char *ft_strjoin(char *s1, char *s2)
{
    char *ret;
    int i;
	int j;

	if (!s1)
		s1 = ft_strdup("\0");
    ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return NULL;
    i = 0;
    while (s1[i])
	{
        ret[i] = s1[i];
		i++;
	}
	j = 0;
    while (s2[j])
        ret[i++] = s2[j++];
    ret[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
    return ret;
}

