#include "libft.h"

int	count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	int		j;
	int		k;
	char	*start;

	words = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	j = 0;
	while (*s)
	{
		k = -1;
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			start = (char *) s;
			while (*s && (*s != c))
				s++;
			words[j] = (char *)malloc(s - start + 1);
			while (k++ < (s - start) - 1)
				words[j][k] = start[k];
			words[j][k] = '\0';
			j++;
		}
	}
	words[j] = NULL;
	return (words);
}

// int	main(void)
// {
// 	char *str1;
// 	char charset1;
// 	char **result1;

// 	str1 = ",a,kon,aaa,iisssssi,aa";
// 	charset1 = ',';
// 	result1 = ft_split(str1, charset1);
// 	printf("Test 1\n");
// 	for (int i = 0; result1[i] != NULL; i++)
// 	{
// 		printf("box %d: %s\n", i, result1[i]);
// 		free(result1[i]);
// 	}
// 	free(result1);
// 	return (0);
// }