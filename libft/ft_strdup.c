/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:33:34 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/16 13:03:43 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ans;

	i = 0;
	ans = (char *)malloc(ft_strlen(s1) + 1);
	while (1)
	{
		ans[i] = s1[i];
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (ans);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_strdup("");
// 	printf("%s\n", str);
// }
