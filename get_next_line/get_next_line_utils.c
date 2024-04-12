#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
    if (!s)
		return (0);
	while (s[i])
		i++;
	return i;
} 

char *ft_strdup(char *s1)
{
	int i;
	char *ans;

	i = 0;
	ans = (char *)malloc(ft_strlen(s1) + 1);
	while (s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	return ans;
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

// char *ft_strjoin(char *s1, char *s2)
// {
//     char *ret;
//     int i;

//     if (!s1)
//     {
//         free(s1);
//         return ft_strdup(s2);
//     }
//     ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//     i = 0;
//     while (*s1)
//     {
//         ret[i] = *s1;
//         i++;
//         s1++;
//     }
//     while (*s2)
//     {
//         ret[i] = *s2;
//         i++;
//         s2++;
//     }
//     ret[i] = '\0';
//     return ret;
// }