/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 02:18:09 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/06 02:19:26 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	window_close(t_vars *vars)
{
	write(1, "window close\n", 13);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	mouse_down(int key, int x, int y, t_dst *lst)
{
	if (key == 4)
	{
		if (lst->zoom <= 1.0)
			return (0);
		else
			lst->zoom -= 0.1;
	}
	else if (key == 5)
		lst->zoom += 0.1;
	printf("%f\n", lst->zoom);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 53)
	{
		write(1, "window close\n", 13);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	loop_hook(t_vars *vars)
{
	t_vars	v;

	v = *vars;
	if (!ft_strncmp(v.arg, "mandelbrot", 10))
		mandelbrot(v.mlx, v.win, v.lst);
	else
		julia(v.mlx, v.win, v.lst);
	return (0);
}
