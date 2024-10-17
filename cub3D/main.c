/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:49:47 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/06/30 16:29:59 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(void)
{
	t_config config;

	config.mlx = mlx_init();
	config.window = ft_new_window(config.mlx, WIDTH, HEIGHT, "Hello world!");

	config.sprite = ft_new_sprite(config.mlx, "block.xpm");
	config.sprite_position.x = 0;
	config.sprite_position.y = 0;
	mlx_put_image_to_window(config.mlx, config.window.reference,
		config.sprite.reference, config.sprite_position.x,
		config.sprite_position.y);

	mlx_key_hook(config.window.reference, *ft_input, &config);
	mlx_loop_hook(config.mlx, *ft_update, &config);
	mlx_loop(config.mlx);
	return (0);
}