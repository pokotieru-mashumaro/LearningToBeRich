/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:53:39 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/06/30 16:59:37 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

int	ft_input(int key, void *param)
{
	t_config	*config;

	config = (t_config *)param;
	mlx_clear_window(config->mlx, config->window.reference);
	if (key == 124)
		config->sprite_position.x += config->sprite.size.x;
	else if (key == 123)
		config->sprite_position.x -= config->sprite.size.x;
	else if (key == 125)
		config->sprite_position.y += config->sprite.size.y;
	else if (key == 126)
		config->sprite_position.y -= config->sprite.size.y;
	else if (key == 15)
		turn_img_to_color(&config->sprite, new_color(255, 0, 0, 0));
	else if (key == 5)
		turn_img_to_color(&config->sprite, new_color(0, 255, 0, 0));
	else if (key == 11)
		turn_img_to_color(&config->sprite, new_color(0, 0, 255, 0));
	mlx_put_image_to_window(config->mlx, config->window.reference,
		config->sprite.reference, config->sprite_position.x,
		config->sprite_position.y);
	printf("Key pressed -> %d\n", key);
	return (0);
}

int	ft_update(void *param)
{
	t_config *config = (t_config *)param;
	static int frame;

	frame++;
	if (frame == FPS)
		config->sprite_position.y += 1;
	else if (frame >= FPS * 2)
	{ 
		config->sprite_position.y -= 1;
		frame = 0;
	}

	mlx_put_image_to_window(config->mlx, config->window.reference,
		config->sprite.reference, config->sprite_position.x,
		config->sprite_position.y);

	return (0);
}