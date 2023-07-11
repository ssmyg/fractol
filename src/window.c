/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:56:55 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/11 13:56:56 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

void	init_vars(t_vars *vars)
{
	vars->scale = 1.0;
	vars->dx = 0.0;
	vars->dy = 0.0;
	vars->is_down = 0;
	vars->down_x = 0.0;
	vars->down_y = 0.0;
	vars->win_w = WINDOW_W;
	vars->win_h = WINDOW_H;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->win_w, vars->win_h,
		"Mandelbrot");
}

void	set_hooks(t_vars *vars)
{
	mlx_hook(vars->win, ON_MOUSEMOVE, 0, mouse_move, vars);
	mlx_hook(vars->win, ON_MOUSEDOWN, 0, mouse_down, vars);
	mlx_hook(vars->win, ON_MOUSEUP, 0, mouse_up, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_do_key_autorepeaton(vars->mlx);
	mlx_hook(vars->win, ON_DESTROY, 0, close, vars);
	mlx_loop_hook(vars->mlx, render_frame, vars);
	mlx_loop(vars->mlx);
}

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}
