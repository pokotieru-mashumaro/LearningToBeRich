#include "minishell.h"

int	find_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && find_set(*str, charset))
			str++;
		if (*str)
			count++;
		while (*str && !find_set(*str, charset))
			str++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	*start;
	int		len;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	i = 0;
	while (*str)
	{
		while (*str && find_set(*str, charset))
			str++;
		start = str;
		if (*str)
		{
			while (*str && !find_set(*str, charset))
				str++;
			len = str - start;
			result[i] = (char *)malloc(len + 1);
			j = 0;
			while (j < len)
			{
				result[i][j] = start[j];
				j++;
			}
			result[i][len] = '\0';
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*str1;
// 	char	*charset1;
// 	char	**result1;

// 	str1 = "s q ";
// 	charset1 = " ";
// 	result1 = ft_split(str1, charset1);
// 	printf("Test 1\n");
// 	for (int i = 0; result1[i] != NULL; i++)
// 	{
// 		printf("box %d: %s\n", i, result1[i]);
// 		free(result1[i]);
// 	}
// 	free(result1);
// 	str1 = "   Machida is in Kanagawa";
// 	charset1 = " ";
// 	result1 = ft_split(str1, charset1);
// 	printf("Test 2\n");
// 	for (int i = 0; result1[i] != NULL; i++)
// 	{
// 		printf("box %d: %s\n", i, result1[i]);
// 		free(result1[i]);
// 	}
// 	free(result1);
// 	str1 = "Machida is in Kanagawa   ";
// 	charset1 = " ";
// 	result1 = ft_split(str1, charset1);
// 	printf("Test 3\n");
// 	for (int i = 0; result1[i] != NULL; i++)
// 	{
// 		printf("box %d: %s\n", i, result1[i]);
// 		free(result1[i]);
// 	}
// 	free(result1);
// 	str1 = "       ";
// 	charset1 = " ";
// 	result1 = ft_split(str1, charset1);
// 	printf("Test 4\n");
// 	for (int i = 0; result1[i] != NULL; i++)
// 	{
// 		printf("box %d: %s\n", i, result1[i]);
// 		free(result1[i]);
// 	}
// 	free(result1); // test4はboxが表示されてはならない
// 	return (0);
// }
