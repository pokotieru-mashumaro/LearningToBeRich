#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return i;
}

char *ft_strdup(char *s1)
{
	int i;
	char *ret;

	i = 0;
	ret = (char *)malloc(ft_strlen(s1) + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return ret;
}

char *concat_two_str(char *s1, char *s2)
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

// int main()
// {
// 	char *s1 = (char *)malloc(5);
// 	s1 = "aiueo";
// 	char *a = concat_two_str(s1, "12345");
// 	printf("%s", a);
// 	return 0;
// }
