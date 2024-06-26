/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:56:55 by susumuyagi        #+#    #+#             */
/*   Updated: 2024/04/29 15:28:00 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keyboard.h"
#include "mlx.h"
#include "mouse.h"
#include "render.h"
#include "window.h"
#include <stdlib.h>

void	init_vars(t_vars *vars)
{
	vars->scale = 200.0;
	vars->dx = 0.0;
	vars->dy = 0.0;
	vars->is_down = 0;
	vars->down_x = 0.0;
	vars->down_y = 0.0;
	vars->keycode = 0;
	vars->color = 120;
	vars->model = NULL;
	vars->is_julia = 0;
	vars->img.img = NULL;
	vars->c[0] = -0.30;
	vars->c[1] = -0.63;
	vars->z = malloc(sizeof(double) * WINDOW_WIDTH * WINDOW_HEIGHT * 2);
	vars->count = malloc(sizeof(int) * WINDOW_WIDTH * WINDOW_HEIGHT);
}

void	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"fractol");
}

void	set_hooks(t_vars *vars)
{
	mlx_hook(vars->win, ON_MOUSEMOVE, 0, mouse_move, vars);
	mlx_hook(vars->win, ON_MOUSEDOWN, 0, mouse_down, vars);
	mlx_hook(vars->win, ON_MOUSEUP, 0, mouse_up, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_do_key_autorepeaton(vars->mlx);
	mlx_hook(vars->win, ON_DESTROY, 0, window_close, vars);
	mlx_loop_hook(vars->mlx, render_frame, vars);
	mlx_loop(vars->mlx);
}

int	window_close(t_vars *vars)
{
	free(vars->z);
	free(vars->count);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
