/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:07:31 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/06 02:19:17 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2 || (ft_strncmp(av[1], "mandelbrot", 10) && ft_strncmp(av[1],
				"julia", 5)))
	{
		write(1, "only one function can be used\n", 30);
		write(1, "-----------------------------\n", 30);
		write(1, "mandelbrot\n", 11);
		write(1, "julia\n", 6);
		return (0);
	}
	vars.lst.zoom = 1.0;
	vars.arg = av[1];
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "sample");
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars.lst);
	mlx_hook(vars.win, ON_DESTROY, 0, window_close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
