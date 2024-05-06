/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:33:59 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/06 03:00:06 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mand_cal(t_dst lst)
{
	int	color;

	color = 0;
	lst.new_re = 0;
	lst.new_im = 0;
	lst.old_re = 0;
	lst.old_im = 0;
	while (lst.new_re * lst.new_re + lst.new_im * lst.new_im < 4
		&& color < MAX_ITER)
	{
		lst.old_re = lst.new_re;
		lst.old_im = lst.new_im;
		lst.new_re = lst.old_re * lst.old_re - lst.old_im * lst.old_im + lst.zx;
		lst.new_im = 2 * lst.old_re * lst.old_im + lst.zy;
		color++;
	}
	return (color);
}

void	mandelbrot(void *mlx, void *win, t_dst lst)
{
	int	color;
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			lst.zx = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * lst.zoom * WIN_WIDTH)
				+ MAN_C_RE;
			lst.zy = (y - WIN_HEIGHT / 2) / (0.5 * lst.zoom * WIN_HEIGHT)
				+ MAN_C_IM;
			i = mand_cal(lst);
			if (i > MAX_ITER - 20)
				color = (i % 255) * 0x0000FF00;
			else if (i > MAX_ITER - 60)
				color = (i % 255) * 0x00FF0000;
			else
				color = (i % 255) * 0x010101;
			mlx_pixel_put(mlx, win, x, y, color);
			x++;
		}
		y++;
	}
}
