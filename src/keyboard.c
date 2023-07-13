/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susumuyagi <susumuyagi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:08:16 by susumuyagi        #+#    #+#             */
/*   Updated: 2023/07/13 11:52:09 by susumuyagi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		window_close(vars);
	if (keycode == KEY_C)
	{
		vars->color = (vars->color + 10) % 360;
		drow_img(vars);
	}
	if (keycode == KEY_0)
	{
		vars->scale = 1.0;
		vars->dx = 0.0;
		vars->dy = 0.0;
		drow_img(vars);
	}
	if (KEY_LEFT <= keycode && keycode <= KEY_UP)
	{
		if (keycode == KEY_LEFT)
			vars->dx += 10.0;
		if (keycode == KEY_RIGHT)
			vars->dx -= 10.0;
		if (keycode == KEY_DOWN)
			vars->dy -= 10.0;
		if (keycode == KEY_UP)
			vars->dy += 10.0;
		drow_img(vars);
	}
	return (0);
}
