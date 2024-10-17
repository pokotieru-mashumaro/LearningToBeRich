/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:26:19 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/06/30 16:27:04 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

void	turn_pixel_to_color(char *pixel, t_color color)
{
	pixel[0] = color.b;
	pixel[1] = color.g;
	pixel[2] = color.r;
	pixel[3] = color.a;
}

/* turns all pixels of <image> to <color> */
void	turn_img_to_color(t_image *image, t_color color)
{
	int x;
	int y;

	y = 0;
	while (y < image->size.y)
	{
		x = 0;
		while (x < image->size.x)
		{
			turn_pixel_to_color(&image->pixels[x * 4 + image->line_size * y],
				color);
			x++;
		}
		y++;
	}
}