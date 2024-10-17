/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:45:26 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/07/01 11:08:47 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ray_casting(t_config config, int player_pos_x, int player_pos_y, double player_angle)
{
	double cur_angle;
	int x;
	int y;
	int i;
	int j;

	cur_angle = player_angle - HALF_FOV;
	x = player_pos_x;
	y = player_pos_y;
	i = 0;
	while (i < NUM_RAYS)
	{
		j = 0;
		while (j < MAX_DEPTH)
		{
			/* ここでlineを出力 */
			// if (x / (TILE * TILE))
			j++;
		}
		cur_angle += DELTA_ANGLE;
		i++;
	}
	
}