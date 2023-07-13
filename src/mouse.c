/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:10:59 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 16:00:57 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keyboard.h"
#include "mouse.h"

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

void	scroll_up(int x2, int y2, t_vars *vars)
{
	if (vars->keycode == KEY_R)
	{
		vars->c[0] += 0.005;
		if (vars->c[0] > 2.0)
			vars->c[0] -= 4.0;
		drow_img(vars);
	}
	else if (vars->keycode == KEY_I)
	{
		vars->c[1] += 0.005;
		if (vars->c[1] > 2.0)
			vars->c[1] -= 4.0;
		drow_img(vars);
	}
	else
	{
		vars->scale *= ZOOM_RATE;
		vars->dx = (vars->dx + x2) * ZOOM_RATE - x2;
		vars->dy = (vars->dy + y2) * ZOOM_RATE - y2;
		drow_img(vars);
	}
}

void	scroll_down(int x2, int y2, t_vars *vars)
{
	if (vars->keycode == KEY_R)
	{
		vars->c[0] -= 0.005;
		if (vars->c[0] < -2.0)
			vars->c[0] += 4.0;
		drow_img(vars);
	}
	else if (vars->keycode == KEY_I)
	{
		vars->c[1] -= 0.005;
		if (vars->c[1] < -2.0)
			vars->c[1] += 4.0;
		drow_img(vars);
	}
	else
	{
		vars->scale /= ZOOM_RATE;
		vars->dx = (vars->dx + x2) / ZOOM_RATE - x2;
		vars->dy = (vars->dy + y2) / ZOOM_RATE - y2;
		drow_img(vars);
	}
}

int	mouse_down(int key, int x, int y, t_vars *vars)
{
	int	x2;
	int	y2;

	x2 = x - vars->win_w / 2;
	y2 = y - vars->win_h / 2;
	if (key == SCROLL_UP)
		scroll_up(x2, y2, vars);
	else if (key == SCROLL_DOWN)
		scroll_down(x2, y2, vars);
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
