/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:25:40 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/06 02:01:55 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	julia_cal(t_dst lst, int x, int y)
{
	int	color;

	lst.zx = 1.5 * (x - WIN_WIDTH / 2) / (0.5 * lst.zoom * WIN_WIDTH) + SHIFT_X;
	lst.zy = (y - WIN_HEIGHT / 2) / (0.5 * lst.zoom * WIN_HEIGHT) + SHIFT_Y;
	color = 0;
	while (lst.zx * lst.zx + lst.zy * lst.zy < 4 && color < MAX_ITER)
	{
		lst.tmp = lst.zx * lst.zx - lst.zy * lst.zy + JULIA_C_RE;
		lst.zy = 2.0 * lst.zx * lst.zy + JULIA_C_IM;
		lst.zx = lst.tmp;
		color++;
	}
	return (color);
}

void	julia(void *mlx, void *win, t_dst	lst)
{
	int		x;
	int		y;
	int		i;
	int		color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			i = julia_cal(lst, x, y);
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
