/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:45:21 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/06/30 17:06:30 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <math.h>

// game settings
# define WIDTH 1200
# define HEIGHT 800
# define HARF_WIDTH 600
# define HARF_HEIGHT 400
# define FPS 60
# define TILE 50

// ray casting settings
# define FOV (M_PI / 3)
# define HALF_FOV (FOV / 2)
# define NUM_RAYS 120
# define MAX_DEPTH 800
# define DELTA_ANGLE (FOV / NUM_RAYS)


// player settings
# define PLAYER_POS_X HARF_WIDTH
# define PLAYER_ANGLE 0
# define PLAYER_SPEED 2

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_window
{
	void		*reference;
	int			x;
	int			y;
}				t_window;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_config
{
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}				t_config;

t_window		ft_new_window(void *mlx, int widht, int height, char *name);
t_image			ft_new_sprite(void *mlx, char *path);

t_color			new_color(int r, int g, int b, int a);
void			turn_img_to_color(t_image *image, t_color color);

int				ft_input(int key, void *program);
int				ft_update(void *param);
#endif