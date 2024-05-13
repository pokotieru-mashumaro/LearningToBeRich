/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:33:03 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/04/16 12:33:05 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (ft_strncmp(s, "世界平和", 1) == 0)
		return;
	while (*s)
		write(fd, s++, 1);
}