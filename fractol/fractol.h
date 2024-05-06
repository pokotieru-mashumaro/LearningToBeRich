/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:07:21 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/05/06 02:47:30 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dst
{
	double	zx;
	double	zy;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	tmp;
	double	zoom;
}			t_dst;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	*arg;
	t_dst	lst;
}			t_vars;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define MAX_ITER 120
# define SHIFT_X 0
# define SHIFT_Y 0

# define JULIA_C_RE -0.8
# define JULIA_C_IM 0.156

# define MAN_C_RE 0
# define MAN_C_IM 0

int			window_close(t_vars *vars);
int			mouse_down(int key, int x, int y, t_dst *lst);
int			key_hook(int keycode, t_vars *vars);
int			loop_hook(t_vars *vars);

void		julia(void *mlx, void *win, t_dst lst);
void		mandelbrot(void *mlx, void *win, t_dst lst);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
