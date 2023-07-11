/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:10:59 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/11 13:11:00 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_vars *vars)
{
	if (vars->is_down)
	{
		vars->dx = vars->down_x - x;
		vars->dy = vars->down_y - y;
		drow_img(vars);
	}
	return (0);
}

int	mouse_down(int key, int x, int y, t_vars *vars)
{
	int	x2;
	int	y2;

	x2 = x - vars->win_w / 2;
	y2 = y - vars->win_h / 2;
	if (key == SCROLL_UP)
	{
		// 拡大
		vars->scale *= ZOOM_RATE;
		vars->dx = (vars->dx + x2) * ZOOM_RATE - x2;
		vars->dy = (vars->dy + y2) * ZOOM_RATE - y2;
		drow_img(vars);
	}
	else if (key == SCROLL_DOWN)
	{
		// 縮小
		vars->scale /= ZOOM_RATE;
		vars->dx = (vars->dx + x2) / ZOOM_RATE - x2;
		vars->dy = (vars->dy + y2) / ZOOM_RATE - y2;
		drow_img(vars);
	}
	else if (key == MOUSE_LEFT)
	{
		vars->is_down = 1;
		vars->down_x = x + vars->dx;
		vars->down_y = y + vars->dy;
	}
	return (0);
}

int	mouse_up(int key, int x, int y, t_vars *vars)
{
	if (key == MOUSE_LEFT)
	{
		vars->is_down = 0;
		vars->down_x = x + vars->dx;
		vars->down_y = y + vars->dy;
	}
	return (0);
}
