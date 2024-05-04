#include "../../includes/push_swap.h"

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

void	split_component(const char *s, char c, char **words)
{
	int		j;
	int		k;
	char	*start;

	j = 0;
	while (*s)
	{
		k = -1;
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			start = (char *)s;
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
}

char	**ft_split(const char *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!words)
		return (NULL);
	split_component(s, c, words);
	return (words);
}
